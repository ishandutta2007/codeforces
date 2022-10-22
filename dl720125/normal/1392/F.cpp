#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int n,_n,a[1000010],sum[1000010],ans;

inline int getint(){
    int r=0;
	char c;
	c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){r=r*10+c-'0';c=getchar();}
    return r;
}

signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=getint();
	int pos=1;
	sum[1]+=a[1];sum[2]-=a[1];
	int pre=a[1];
	for(int i=2;i<=n;i++){
		int x=a[i]-pre-1,now=a[i];
		if(x>0){
			if(pos+x-1<i-1){
				sum[pos]++;sum[pos+x]--;
				pos=pos+x;now-=x;
			}
			else{
				sum[pos]++;sum[i]--;
				now-=(i-1-pos+1);pre++;
				int nw=now-pre;pos=1;
				if(nw>1){
					int c=nw/i*(i-1);
					if(nw%i>0) c+=(nw%i-1);
					now-=c;
					sum[1]+=c/(i-1);sum[i]-=c/(i-1);
					pre+=c/(i-1);
					c=c%(i-1);
					if(c>0){
						sum[1]++;sum[c+1]--;
					}
					pos+=c;
				}
			}
		}
		if(pos==1&&now==pre) pos=i;
		sum[i]+=now;sum[i+1]-=now;
		pre=now;
	}
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1];
		printf("%I64d ",sum[i]);
	}
	puts("");
	return 0;
}
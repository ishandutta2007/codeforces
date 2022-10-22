#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int h,g,a[4000010],idx[4000010],dist[4000010],t[4000010];

inline int getint(){
    int r=0;
	char c;
	c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9'){r=r*10+c-'0';c=getchar();}
    return r;
}

inline bool del(int x)
{
	int ls=2*x,rs=2*x+1;
	if(a[ls]==0&&a[rs]==0){
		if(dist[x]<=g) return false;
		idx[a[x]]=0;a[x]=0;
		return true;
	}
	else{
		if(a[ls]>a[rs]){
			int pre=a[ls];
			if(del(ls)){
				a[x]=pre;
				idx[a[x]]=x;
				return true;
			}
			else return false;
		}
		else{
			int pre=a[rs];
			if(del(rs)){
				a[x]=pre;
				idx[a[x]]=x;
				return true;
			}
			else return false;
		}
	}
}

signed main()
{
	int cases;
	cin>>cases;
	while(cases--){
		h=getint();g=getint();
		int n=1;
		for(int i=1;i<=h;i++) n*=2;
		n--;
		for(int i=1;i<=n*2+1;i++){
			a[i]=0;t[i]=0;idx[i]=0;dist[i]=0;
		}
		for(int i=1;i<=n;i++) a[i]=getint();
		for(int i=1;i<=n;i++){
			idx[a[i]]=i;t[i]=a[i];
		}
		for(int i=1;i<=n;i++) dist[i]=dist[i/2]+1;
		sort(t+1,t+n+1);reverse(t+1,t+n+1);
		long long ans=0ll;
		vector<int> res;
		for(int i=1;i<=n;i++){
			int pos=idx[t[i]];
			if(del(pos)) res.push_back(pos);
			else{
				ans+=(long long)t[i];
			}
		}
		printf("%I64d\n",ans);
		for(int i=0;i<res.size();i++) printf("%d ",res[i]);
		printf("\n");
	}
	return 0;
}
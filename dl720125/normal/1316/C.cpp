#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,m,p,a[1000010],b[1000010];

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
	cin>>n>>m>>p;
	for(int i=1;i<=n;i++) a[i]=getint();
	for(int i=1;i<=m;i++) b[i]=getint();
	int pos1=1;
	for(int i=1;i<=n;i++) if(a[i]%p!=0){
		pos1=i;break;
	}
	int pos2=1;
	for(int i=1;i<=m;i++) if(b[i]%p!=0){
		pos2=i;break;
	}
	cout<<pos1+pos2-2<<endl;
	return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxn 200020
int n,q;
int t[maxn],a[maxn]; 
int main(){
	n=getint(),q=getint();
	ll ans=0;
	for(int i=1;i<=n;++i)a[i]=getint(),t[i]=0,ans+=a[i];
	int tq=-1,ta=0;
	for(int i=1;i<=q;++i){
		int x=getint(),y=getint(),z;
		if(x==1){
			z=getint();
			if(t[y]<tq){
				t[y]=i;
				ans+=z-ta;
				a[y]=z;
			}
			else {
				t[y]=i;
				ans+=z-a[y];
				a[y]=z;
			}
		}
		else{
			tq=i;
			ta=y;
			ans=1ll*n*y;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
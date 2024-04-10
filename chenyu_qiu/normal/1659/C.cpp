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
int x[maxn];
int main(){
	int t=getint();
	while(t--){
		int n=getint(),a=getint(),b=getint();
		x[0]=0;
		for(int i=1;i<=n;++i)x[i]=getint();
		ll ans=0;
		int pos=0;
		for(int i=1;i<=n;++i){
			ans+=1ll*b*(x[i]-x[pos]);
			if(1ll*b*(n-i)>=1ll*a)ans+=1ll*a*(x[i]-x[pos]),pos=i;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
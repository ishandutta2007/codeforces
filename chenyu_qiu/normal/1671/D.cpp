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
int n,x,a[maxn];
int main(){
	int t=getint();
	while(t--){
		n=getint(),x=getint();
		for(int i=1;i<=n;++i)a[i]=getint(); 
		ll ans=0;
		int mn=a[1],mx=a[1];
		for(int i=2;i<=n;++i)mn=min(mn,a[i]),mx=max(mx,a[i]);
		if(mn>1){
			ll tmp=a[1]-1;
			for(int i=2;i<=n;++i)tmp=min(tmp,(ll)a[i-1]-1+a[i]-1-abs(a[i-1]-a[i]));
			tmp=min(tmp,(ll)a[n]-1);
			ans+=tmp;
		}
		if(x>mx){
			ll tmp=x-a[1];
			for(int i=2;i<=n;++i)tmp=min(tmp,(ll)x-a[i-1]+x-a[i]-abs(a[i-1]-a[i]));
			tmp=min(tmp,(ll)x-a[n]);
			ans+=tmp;
		}
		for(int i=2;i<=n;++i)ans+=abs(a[i]-a[i-1]); 
		printf("%lld\n",ans);
	}
	return 0;
}
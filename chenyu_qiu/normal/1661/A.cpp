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
ll a[50],b[50];
int main(){
	int t=getint();
	while(t--){
		int n=getint(); 
		for(int i=1;i<=n;++i)a[i]=getint();
		for(int i=1;i<=n;++i)b[i]=getint();
		ll ans=0;
		for(int i=1;i<n;++i)ans+=min(abs(a[i+1]-a[i])+abs(b[i+1]-b[i]),abs(a[i+1]-b[i])+abs(b[i+1]-a[i]));
		printf("%lld\n",ans);
	} 
	return 0;
}
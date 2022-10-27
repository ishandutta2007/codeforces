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
int a[200020];
int main(){
	int t=getint();
	while(t--){
		int n=getint(),x=getint();
		for(int i=1;i<=n;++i)a[i]=getint();
		sort(a+1,a+n+1);
		int tmp=0,pos;
		for(pos=1;pos<=n;++pos){
			tmp+=a[pos];
			if(tmp>x){
				tmp-=a[pos];
				break;
			} 
		}
		--pos;
		ll ans=0;
		for(;pos;--pos){
			ans+=(x-tmp)/pos+1;
			tmp-=a[pos];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
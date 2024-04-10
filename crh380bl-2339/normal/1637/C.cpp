#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[100005];
int chk(int n){
	int i;
	if(n==3&&a[2]%2==1)return 0;
	for(i=2;i<n;++i)if(a[i]!=1)return 1;
	return 0;
}
int main(){
	int n,t,i;
	scanf("%d",&t);
	while(t--){
		ll ans=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(i!=1&&i!=n){
				ans=ans+((1LL+a[i])>>1);
			}
		}
		if(!chk(n))puts("-1");
		else printf("%lld\n",ans);
	}
	return 0;
}
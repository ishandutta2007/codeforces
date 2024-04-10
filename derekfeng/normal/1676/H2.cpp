#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tc,n;
int b[200004];
ll ans;
void upd(int i){
	for(;i;i-=i&-i)b[i]++;
}
void qry(int i){
	for(;i<=n;i+=i&-i)ans+=b[i];
}
void sol(){
	scanf("%d",&n);memset(b,0,(n+2)<<2);ans=0;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		qry(x),upd(x);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&tc);
	while(tc--)sol();
}
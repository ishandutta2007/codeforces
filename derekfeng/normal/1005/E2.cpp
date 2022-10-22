#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200004];
int bit[400004];
void upd(int id){
	for(;id<=n+n+1;id+=(id&-id))bit[id]++;
}
int qr(int id){
	int res=0;
	for(;id;id-=(id&-id))res+=bit[id];
	return res;
}
ll got(int x){
	ll ans=0;
	int sum=0;
	for(int i=1;i<=n+n+1;i++)bit[i]=0;
	upd(n+1);
	for(int i=1;i<=n;i++){
		int w=(a[i]>=x?1:-1);
		sum+=w;
		ans+=qr(sum+n);
		upd(sum+n+1);
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	printf("%I64d",got(m)-got(m+1));
}
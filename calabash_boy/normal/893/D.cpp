#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
typedef long long LL;
LL r[maxn],sum[maxn];
int a[maxn];
int n;LL d;
void input(){
	scanf("%d%I64d",&n,&d);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for (int i=1;i<=n;i++){
		sum[i] = sum[i-1]+a[i];
	}
	r[n] = sum[n];
	for (int i=n-1;i>=1;i--){
		r[i] = max(r[i+1],sum[i]);
	}
}
void solve(){
	if (r[1]>d){
		cout<<-1<<endl;
		return ;
	}
	long long tot =0;
	int ans =0;
	for (int i=1;i<=n;i++){
		if (a[i]!=0)continue;
		if (sum[i]+tot>=0)continue;
		ans++;
		tot+= d-(r[i]+tot);
		if (sum[i]+tot>=0)continue;
		else{
			cout<<-1<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
}
int main(){
	input();
	solve();
	return 0;
}
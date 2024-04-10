#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll st[20][200004],a[200004];
int n,T,lg[200004];
ll qry(int l,int r){
	int Lg=lg[r-l+1];
	return __gcd(st[Lg][l],st[Lg][r-(1<<Lg)+1]);
}
void solve(){
	int ans=1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=2;i<=n;i++)st[0][i]=abs(a[i]-a[i-1]);
	st[0][1]=0;
	for(int i=1;i<=lg[n];i++)
		for(int j=1;j+(1<<i)-1<=n;j++)
			st[i][j]=__gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	int cur=1;
	for(int i=2;i<=n;i++){
		while(cur<i&&qry(cur+1,i)==1)cur++;
		ans=max(ans,i-cur+1);
	}
	cout<<ans<<"\n";
}
int main(){
	for(int i=2;i<=2e5;i++)lg[i]=lg[i>>1]+1;
	for(cin>>T;T--;)solve();
}
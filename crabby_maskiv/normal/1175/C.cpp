#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f3f3f3f3fll;
const ll mod=998244353;
int n,m;
int T;
ll a[N];

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		ll ans=inf;int pos=0;
		for(i=1;i<=n-m;i++){
			if(a[i+m]-(a[i]+a[i+m])/2<ans){
				ans=a[i+m]-(a[i]+a[i+m])/2;
				pos=(a[i]+a[i+m])/2;
			}
		}
		cout<<pos<<endl;
	}
	return 0;
}
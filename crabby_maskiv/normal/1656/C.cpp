#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n;
int a[N];
void solve(){
	int i;
	sort(a+1,a+n+1);
	int c1=0;
	for(i=1;i<=n;i++)
		c1+=(a[i]==1);
	if(c1==0){
		cout<<"YES"<<endl;
		return;
	}
	for(i=1;i<n;i++){
		if(a[i+1]==a[i]+1){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		solve();
	}
	return 0;
}
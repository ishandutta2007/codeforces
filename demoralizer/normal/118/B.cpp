#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

void solve(){
	int n,x,d=0;
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<n-i;j++)
			cout<<"  ";
		for(int k=0;k<i;k++)
			cout<<k<<" ";
		cout<<i;
		for(int k=i-1;k>=0;k--)
			cout<<" "<<k;
		cout<<"\n";
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<n-i;j++)
			cout<<"  ";
		for(int k=0;k<i;k++)
			cout<<k<<" ";
		cout<<i;
		for(int k=i-1;k>=0;k--)
			cout<<" "<<k;
		cout<<"\n";
	}
}
signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
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
	int n,v=0;
	cin>>n;
	int a[n];
	for(int& i:a){
		cin>>i;
	}
	if(a[n-1]==0)v=1;
	else if(a[n-1]==15)v=-1;
	else if(n==1);
	else{
		if(a[n-1]>a[n-2])v=1;
		else v=-1;
	}
	if(!v)cout<<-1;
	else if(v==1)cout<<"UP";
	else cout<<"DOWN";
}
signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
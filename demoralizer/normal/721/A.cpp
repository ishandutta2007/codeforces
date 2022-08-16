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
	int n;string s;
	cin>>n>>s;
	vc<int> v;
	int c=0;
	for(char z:s){
		if(z=='B'){
			c++;
		}
		else{
			if(c)v.pb(c);c=0;
		}
	}
	if(c)v.pb(c);
	cout<<v.size()<<"\n";
	for(int i:v){
		cout<<i<<" ";
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
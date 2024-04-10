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
	string s;cin>>s;
	s+='A';
	set<int> x;
	x.insert('A');x.insert('E');
	x.insert('I');x.insert('O');
	x.insert('U');x.insert('Y');
	int c=0,m=0;
	for(char z:s){
		c++;
		if(x.find(z)!=x.end()){
			m=max(m,c);
			c=0;
		}
	}
	cout<<m;
}
signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
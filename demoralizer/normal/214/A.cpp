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
	int n,m,a,b,t=0,x,y,z=0;
	cin>>n>>m;
	for(int i=0;;i++){
		t=0;
		for(int j=0;;j++){
			if((i+j*j==m)&&(i*i+j==n))z++;
		if((i+j*j>m)||(i*i+j>n)){if(j==0)t=1;break;}
		}
		if(t) break;
	}
	cout<<z;
}
signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
/*int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}*/


void solve(){
	int n,k;
	cin>>n>>k;int f=0;
	if(1+k*(k-1)/2<n){cout<<-1;return;}
	int l=1,u=k;
	while(u>=l){
		int m=(l+u)/2;
		int ans=1+k*(k-1)/2-m*(m-1)/2;
		if(ans<n)u=m-1;
		else{
			l=m+1;
			f=max(m,f);
		}
	}
	cout<<(k-f);
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
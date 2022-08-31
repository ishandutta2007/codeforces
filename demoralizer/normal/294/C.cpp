#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
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

int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}
int fact[1005],invfact[1005];
int PRIME;
void init(int p){
	PRIME=p;
	fact[0]=1;
	int i;
	for(i=1;i<1005;i++){
		fact[i]=(i*fact[i-1])%p;
	}
	i--;
	invfact[i]=pw(fact[i],p-2,p);
	for(i--;i>=0;i--){
		invfact[i]=(invfact[i+1]*(i+1))%p;
	}
}
int ncr(int n,int r){
	return (((fact[n]*invfact[r])%PRIME)*invfact[n-r])%PRIME;
}
int a[1005];vc<int> v;
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int t;
    	cin>>t;
    	a[t]=1;
    }
    if(a[1])v.pb(0);int c=0;
    for(int i=1;i<=n;i++){
    	if(a[i]){if(c)v.pb(c);c=0;}
    	else c++;
    }
    v.pb(c);c=0;
    int ans=1;
    for(int x:v){
    	c+=x;
    	ans*=invfact[x];
    	ans%=M;
    }
    ans=(ans*fact[c])%M;
    for(int i=1;i<v.size()-1;i++){
    	int k=v[i];
    	ans=(ans*pw(2,k-1,M))%M;
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    init(M);
    //cin>>t;
    while(t--) solve();
    return 0;
}
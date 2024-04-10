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
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

int fact[1000007],invfact[1000007];
void init(){
    fact[0]=1;
    for(int i=1;i<1000004;i++){fact[i]=i*fact[i-1]%M;}
    invfact[1000002]=pw(fact[1000002],M-2,M);
    for(int i=1000001;i>=0;i--){
        invfact[i]=(i+1)*invfact[i+1]%M;
    }
}
int ncr(int n,int r,int p){
    return (((fact[n]*invfact[n-r])%p)*invfact[r])%p;
}
void solve(){
    init();
    int n,a,b;
    cin>>a>>b>>n;
    int ans=0;
    for(int i=0;i<=n;i++){
        int t=a*i+b*(n-i),k=0;
        while(t>0){
            int d=t%10;
            if(d!=a&&d!=b)k=1;
            t/=10;
        }
        if(k)continue;
        ans=(ans+ncr(n,i,M))%M;
    }
    cout<<ans;
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
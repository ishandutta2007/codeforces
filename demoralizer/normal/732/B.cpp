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
    int n,k,f,s,r=0;vc<int> v;
    cin>>n>>k>>f;
    v.pb(f);n--;
    while(n--){
        cin>>s;
        if(f+s<=k){
            r+=k-f-s;
            s=k-f;
        }
        v.pb(s);
        f=s;
    }
    cout<<r<<"\n";
    for(int a:v)cout<<a<< " ";
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
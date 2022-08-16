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
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int a[5100];mii c;
map<int,vc<int> > v;
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v[a[i]].pb(i);
    }
    int z=0;
    for(auto u:v){
        if(u.sc.size()>k){cout<<"NO";return;}
        for(auto r:u.sc){
            c[r]=z;
            z++;z%=k;
        }
    }
    cout<<"YES\n";
    for(auto i:c)cout<<(i.sc+1)<<" ";
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
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
    map<int,vc<int> > m;
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        m[t].pb(i);
        s+=t;
    }
    s=2*s/n;
    for(int i=0;i<(n/2);i++){
        int x=(*m.begin()).fr;
        cout<<m[x].back();
        m[x].pop_back();
        if(m[x].empty())m.erase(x);
        x=s-x;
        cout<<" "<<m[x].back()<<"\n";
        m[x].pop_back();
        if(m[x].empty())m.erase(x);
    }
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
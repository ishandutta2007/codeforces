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

map<pii,int> m;
void solve(){
    int n;
    cin>>n;
    int x[n+5],y[n+5],a[n+5],b[n+5];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int j=0;j<n;j++){
        m[{x[0]+a[j],y[0]+b[j]}]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            int tx=x[i]+a[j],ty=y[i]+b[j];
            if(m.find({tx,ty})==m.end())continue;
            m[{tx,ty}]++;
            if(m[{tx,ty}]==n){
                cout<<tx<<" "<<ty;
                return;
            }
        }
    }
    if(n==1)
    cout<<(x[0]+a[0])<<" "<<(y[0]+b[0]);
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
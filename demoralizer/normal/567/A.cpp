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

pii x[100005],y[100005];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        x[i]={t,i};
    }
    sort(x,x+n);
    y[x[0].sc]={x[1].fr-x[0].fr,x[n-1].fr-x[0].fr};
    y[x[n-1].sc]={x[n-1].fr-x[n-2].fr,x[n-1].fr-x[0].fr};
    for(int i=1;i<n-1;i++){
        y[x[i].sc]={min(x[i].fr-x[i-1].fr,x[i+1].fr-x[i].fr),max(x[i].fr-x[0].fr,x[n-1].fr-x[i].fr)};
    }
    for(int i=0;i<n;i++){
        cout<<y[i].fr<<" "<<y[i].sc<<"\n";
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
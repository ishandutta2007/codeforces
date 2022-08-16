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

int a[100005];
pii s[400];
vc<int> v[1000];
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        s[i]={a,b};
    }
    int fa=0,minin=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[j].fr<=i&&s[j].sc>=i){
                v[i].pb(j);
                for(int k=s[j].fr;k<=s[j].sc;k++){
                    a[k]--;
                }
            }
        }
        int mn=a[i];
        int mx=a[1];
        for(int z=1;z<=n;z++){
            mx=max(mx,a[z]);
        }
        int ca=mx-mn;
        if(i==1)fa=ca;
        if(ca>fa){
            fa=ca;
            minin=i;
        }
        for(int j:v[i]){
            for(int k=s[j].fr;k<=s[j].sc;k++){
                a[k]++;
            }
        }
    }
    cout<<fa<<"\n"<<v[minin].size()<<"\n";
    for(int i:v[minin]){
        cout<<i<<" ";
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
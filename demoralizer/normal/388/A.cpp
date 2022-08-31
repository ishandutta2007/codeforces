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
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

vc<int> v;
int x[109];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        x[t]++;
    }
    for(int i=0;i<=100;i++){
        int u=0;
        while(x[i]>0){
            if(u<v.size()){
                v[u]++;if(v[u]>i)u++;
            }
            else{
                v.pb(1);if(v[u]>i)u++;
            }
            x[i]--;
        }
    }
    cout<<(v.size());
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
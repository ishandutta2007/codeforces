#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)                   (x).begin(),(x).end()
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

int a[100005],b[100005];
vc<int> x,y,z;
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=2;i<n;i++){
        if(a[i]<a[i-1]&&a[i]<a[i+1]){
            x.pb(i);
        }
        else if(a[i]<a[i+1]){
            y.pb(i);
        }
        else if(a[i]<a[i-1]){
            z.pb(i);
        }
    }

    for(int i=0;i<m;i++){
        int l,r;
        cin>>l>>r;
        if(l==r||l+1==r){cout<<"Yes\n";continue;}
        auto it=lower_bound(all(x),l+1);
        if(it!=x.end()&&(*it<r)){cout<<"No\n";continue;}
        it=lower_bound(all(z),l+1);
        if(it==z.end()||(*it>=r)){cout<<"Yes\n";continue;}
        auto it2=lower_bound(all(y),*it);
        if(it2==y.end()||(*it2>=r))cout<<"Yes\n";
        else cout<<"No\n";
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
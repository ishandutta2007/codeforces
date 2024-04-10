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

map<int,pii> m;
int b[100005];
void solve(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int j=1;j<=n;j++){
        int i=a[j];
        b[j]=i;
        b[j]+=b[j-1];
        m[i].fr++;
        if(m[i].fr==1)m[i].sc=j;
    }
    int mx=0,mn=-1;
    //for(int i=0;i<=n;i++)cout<<b[i]<<" ";
    for(auto z:m){
        int lmx=0;
        lmx+=z.sc.fr;
        int u=z.sc.sc,l=0,f=u-1;
        while(u>=l){
            int mid=(l+u)/2;
            int ss=b[z.sc.sc-1]-b[mid];
            ss=z.fr*(z.sc.sc-mid-1)-ss;
            if(k<ss){
                l=mid+1;
            }
            if(k>=ss){
                f=mid;
                u=mid-1;
            }
        }
        lmx+=z.sc.sc-f-1;
        if(lmx>mx){
            mx=lmx;
            mn=z.fr;
        }
    }
    cout<<mx<<" "<<mn;
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
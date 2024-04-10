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

int a[100009];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i>0)a[i]+=a[i-1];
    }
    a[n]=a[n-1]+1;
    int t;
    cin>>t;
    while(t--){
        int x,ans=-1;
        cin>>x;
        int l=0,u=n;
        while(l<=u){
            int m=(l+u)/2;
            if(x<=a[m]){
                ans=m;
                u=m-1;
            }
            else l=m+1;
        }
        ans++;
        cout<<ans<<"\n";
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
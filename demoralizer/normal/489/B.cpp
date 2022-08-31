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
    int n,m;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>m;
    int b[m];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a,a+n,greater<int>());
    sort(b,b+m,greater<int>());
    int i=0,j=0,c=0;
    while(i<n&&j<m){
        if(a[i]-1>b[j])i++;
        else if(a[i]+1<b[j])j++;
        else{
            c++;
            i++;
            j++;
        }
    }
    cout<<c;
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
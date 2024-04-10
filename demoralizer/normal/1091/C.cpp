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

set<int> s;
void solve(){
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        if(n%i)continue;
        int k=n/i;
        k=k*(k-1)/2;
        k*=i;
        k+=n/i;
        s.insert(k);
        int j=i;
        i=n/i;
        k=n/i;
        k=k*(k-1)/2;
        k*=i;
        k+=n/i;
        s.insert(k);
        i=j;
    }
    for(set<int>::iterator i=s.begin();i!=s.end();i++){
        cout<<(*i)<<" ";
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
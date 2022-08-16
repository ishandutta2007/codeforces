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
    msi m;
    m["Tetrahedron"]=4;m["Cube"]=6;m["Octahedron"]=8;m["Dodecahedron"]=12;m["Icosahedron"]=20;
    int n,s=0;
    cin>>n;
    string a;
    for(int i=0;i<n;i++){
        cin>>a;
        s+=m[a];
    }
    cout<<s;
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
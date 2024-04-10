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
    int n;
    cin>>n;
    mii m;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        m[b]++;
    }
    if(m.size()==1){
int k=(m.begin())->sc;
cout<<"0 "<<((k)*(k-1)/2);
}
    else{
        auto x=m.begin();
        int a=x->fr,b=x->sc;
        x=m.end();
        x--;
        int c=x->fr,d=x->sc;
        cout<<(c-a)<<" "<<(b*d);
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
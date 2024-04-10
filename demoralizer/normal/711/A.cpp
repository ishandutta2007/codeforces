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
    int n,k=0;
    cin>>n;
    string s[2*n+5],t;
    for(int i=0;i<n;i++){
        cin>>t;
        s[2*i+1]=t.substr(0,2);
        s[2*i+2]=t.substr(3,2);
    }
    for(int i=0;i<=2*n;i++){
        if(s[i]=="OO"){s[i]="++";k=1;break;}
    }
    if(k){
        cout<<"YES\n";
        for(int i=0;i<n;i++){
            cout<<s[2*i+1]<<"|"<<s[2*i+2]<<"\n";
        }
        return;
    }
    cout<<"NO";
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
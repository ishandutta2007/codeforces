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
    mii m;
    m['q']=9;
    m['r']=5;
    m['b']=3;
    m['n']=3;
    m['p']=1;
    m['k']=0;
    int w=0,b=0;
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        for(char c:s){
            if(c=='.')continue;
            if(c<'a'){
                c+=32;
                b+=m[c];
            }
            else{
                w+=m[c];
            }
        }
    }
    if(b>w)cout<<"White";
    else if(b==w)cout<<"Draw";
    else cout<<"Black";
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
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

string s;
mii m;
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        int c=0,d=0,e=0;
        for(int j=0;j<s.size();j++){
            if(s.at(j)=='(')c++;
            else{
                c--;
                if(c<0)d=1;
            }
        }
        c=0;
        for(int j=s.size()-1;j>=0;j--){
            if(s.at(j)==')')c++;
            else{
                c--;
                if(c<0)e=1;
            }
        }
        if(d&&e)continue;
        if(d&&(c<0))continue;
        if(e&&(c>0))continue;
        m[c]++;
    }
    int k=0;
    for(pii a:m){
        if(a.fr>=0)break;
        int x=a.fr,y=a.sc,z=m[-x];
        k+=min(y,z);
    }
    k+=m[0]/2;
    cout<<k;
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
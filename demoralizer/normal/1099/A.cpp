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
    int w,h,u1,u2,d1,d2;
    cin>>w>>h>>u1>>d1>>u2>>d2;
    if(d2>d1){
        int t=d2;
        d2=d1;
        d1=t;
        t=u2;
        u2=u1;
        u1=t;
    }
    for(int i=1;h>0;i++){
        w+=h;
        if(h==d1){
            w-=u1;
            if(w<0)w=0;
        }
        if(h==d2){
            w-=u2;
            if(w<0)w=0;
        }
        h-=1;
    }
    cout<<w;
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
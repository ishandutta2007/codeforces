#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int n,T;
char s[MAXN],t[MAXN];
string ss,tt;
void solve(){
    cin>>n>>(s+1)>>(t+1);
    ss.clear();tt.clear();
    rep(i,1,n)if(s[i]!='b')ss+=s[i];
    rep(i,1,n)if(t[i]!='b')tt+=t[i];
    if(ss!=tt){cout<<"NO\n";return;}
    int sc[3]={0},tc[3]={0};
    rep(i,1,n){
        sc[s[i]-'a']++;tc[t[i]-'a']++;
        if(sc[0]<tc[0] || sc[2]>tc[2]){cout<<"NO\n";return;}
    }
    cout<<"YES\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();
    return 0;
}
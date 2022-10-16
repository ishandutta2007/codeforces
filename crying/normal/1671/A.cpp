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
const int MAXN=100;
int T,n;
char s[MAXN];
void solve(){
    cin>>(s+1);
    n=strlen(s+1);
    rep(i,1,n)if(s[i-1]!=s[i] && s[i+1]!=s[i]){cout<<"NO\n";return;}
    cout<<"YES\n";
}
int main(){
    cin>>T;
    while(T--)solve();


    return 0;
}
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
const int MAXN=1010;
int T,n,m,x,y,d;
void solve(){
    cin>>n>>m>>x>>y>>d;
    if(n-x+m-y<=d){
        cout<<"-1\n";
        return;
    }
    if( (x-1>d && m-y>d) || (y-1>d && n-x>d))cout<<n+m-2<<"\n";
    else cout<<"-1\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}
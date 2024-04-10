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
int T,n,m;
void solve(){
    cin>>n>>m;
    if(n==1 && m==1){
        cout<<"0\n";return;
    }
    if(n==1){
        cout<<m<<"\n";return;
    }
    if(m==1){
        cout<<n<<"\n";return;
    }
    int ans=(n-1)+(m-1)+1+min(n-1,m-1);
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
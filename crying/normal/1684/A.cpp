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
int T,n;
void solve(){
    cin>>n;
    if(n<100){
        cout<<n%10<<endl;
        return;
    }
    int minn=1e9;
    while(n){
        minn=min(minn,n%10);
        n/=10;
    }
    cout<<minn<<endl;
}
int main(){
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}
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
ll T,n,m,S;
vector<ll>ret;
void solve(ll D){
    rep(a,0,1)rep(b,0,1)rep(c,0,1)rep(d,0,1){
        int up=m-a-b,down=m-c-d;
        if(up%D || down%D)continue;
        int l=n-(!a)-(!c),r=n-(!b)-(!d);
        if(l%D || r%D)continue;
        ret.push_back(D);
        return;    
    }
}
void solve(){
    cin>>n>>m;
    ret.clear();
    S=(n-2+m-2)*2+4;
    for(ll i=1;i<=S;i++){
        if(i*i>S)break;
        if(S%i==0){
            solve(i);
            if(S/i!=i)solve(S/i);
        }
    }
    sort(ret.begin(),ret.end());
    cout<<ret.size()<<' ';
    for(auto u:ret)cout<<u<<' ';cout<<endl;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
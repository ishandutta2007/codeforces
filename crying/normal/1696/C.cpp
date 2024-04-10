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
int T,n,m,k;
vector<array<ll,2> >a;
vector<array<ll,2> >b;
void solve(){
    cin>>n>>m;
    ll val=m;
    a.clear();b.clear();
    rep(i,1,n){
        int num;cin>>num;
        int tmp=num;
        while(tmp%m==0){
            tmp/=m;
        }
        int cnt=num/tmp;
        if(a.empty() || a.back()[0]!=tmp)a.push_back({tmp,cnt});
        else{
            auto info=a.back();a.pop_back();
            info[1]+=cnt;
            a.push_back(info);
        }
    }
    cin>>k;
    rep(i,1,k){
        int num;cin>>num;
        int tmp=num;
        while(tmp%m==0){
            tmp/=m;
        }
        int cnt=num/tmp;
        if(b.empty() || b.back()[0]!=tmp)b.push_back({tmp,cnt});
        else{
            auto info=b.back();b.pop_back();
            info[1]+=cnt;
            b.push_back(info);
        }
    }
    if(a.size()!=b.size()){
        cout<<"No\n";return;
    }
    int sz=a.size();
    rep(i,0,sz-1){
        if(a[i]!=b[i]){
            cout<<"No\n";return;
        }
    }
    cout<<"Yes\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
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
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e9;
ll T,n,x,a[MAXN],f[MAXN];
map<ll,ll>b;
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>x;
        b.clear();
        rep(i,1,n){
            cin>>a[i];
        }
        sort(a+1,a+1+n,greater<ll>());
        rep(i,1,n){
            b[a[i]]++;
            if(b[a[i]*x]){
                b[a[i]]--;b[a[i]*x]--;
            }
        }
        ll cnt=0;
        for(auto p:b){
            cnt+=p.second;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
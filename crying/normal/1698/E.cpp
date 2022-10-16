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
const int MAXN=2e5+10,mod=998244353;
int T,n,s,a[MAXN],b[MAXN];
int occ[MAXN],S[MAXN];
int arr[MAXN],tot;
void solve(){
    cin>>n>>s;
    rep(i,1,n){
        int num;cin>>num;
        a[num]=i;
        b[i]=-1;
    }
    rep(i,1,n){
        int num;cin>>num;
        if(num!=-1)b[num]=i;
    }
    rep(i,1,n)occ[i]=0;
    rep(i,1,n)if(b[i]!=-1)occ[b[i]]=i;
    S[n+1]=0;
    per(i,n,1)S[i]=S[i+1]+(b[i]==-1);
    tot=0;
    rep(i,1,n){
        int pos=occ[a[i]];
        if(pos==0){
            arr[++tot]=max(1,i-s);
            continue;
        }
        if(pos<i-s){
            cout<<"0\n";
            return;
        }
    }
    sort(arr+1,arr+1+tot,greater<int>());
    int ret=1;
    rep(i,1,tot){
        if(i>S[arr[i]]){
            ret=0;break;
        }
        ret=1ll*ret*(S[arr[i]]-i+1)%mod;
    }
    cout<<ret<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
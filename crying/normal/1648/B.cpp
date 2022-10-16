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
const int MAXN=1e6+10;
int T,n,m,a[MAXN];
int tag[MAXN];
int qry(int x,int y){return tag[y]-tag[x-1];}
void solve(){
    cin>>n>>m;
    rep(i,1,m)tag[i]=0;
    rep(i,1,n)cin>>a[i],tag[a[i]]++;
    rep(i,1,m)tag[i]+=tag[i-1];
    rep(i,1,m){
        if(qry(i,i)==0){
            rep(j,1,m){
                if(i*j>m)break;
                int L=i*j,R=min((i+1)*j-1,m);
                if(qry(j,j)==0)continue;
                if(qry(L,R)){
                    cout<<"No"<<endl;return;
                }
            }
        }
    }
    cout<<"Yes"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}
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
const int MAXN=2e5+10;
int T,n,m;
vector<int>a[MAXN],b[MAXN];
void solve(){
    cin>>n>>m;
    int pre1=0,pre2=0;
    rep(i,1,n){
        a[i].resize(m+1);b[i].resize(m+1);
        rep(j,1,m)cin>>a[i][j],b[i][j]=a[i][j];
        sort(b[i].begin(),b[i].end());
    }
    rep(i,1,n){
        int pos1=0,pos2=0;
        rep(j,1,m){
            if(b[i][j]==a[i][j])continue;
            if(!pos1)pos1=j;
            else if(!pos2)pos2=j;
            else{
                cout<<-1<<'\n';return;
            }
        }
        if(!pos1)continue;
        if(!pre1){
            pre1=pos1;pre2=pos2;
        }else{
            if(pre1!=pos1 || pre2!=pos2){
                cout<<-1<<'\n';return;
            }
        }
    }
    if(!pre1)cout<<"1 1\n";
    else{
        rep(i,1,n)swap(a[i][pre1],a[i][pre2]);
        rep(i,1,n)rep(j,1,m)if(a[i][j]!=b[i][j]){
            cout<<-1<<'\n';return;
        }
        cout<<pre1<<' '<<pre2<<'\n';
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        solve();
    }


    return 0;
}
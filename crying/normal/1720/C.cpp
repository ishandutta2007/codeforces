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
const int MAXN=510;
int T,n,m;
string s[MAXN];
int check(int x,int y){
    if(s[x][y]=='1')return 0;
    rep(ax,-1,1)rep(ay,-1,1){
        if(ax==0 && ay==0)continue;
        int p=x+ax,q=y+ay;
        if(p>=1 && p<=n && q>=1 && q<=m && s[p][q]=='0'){
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>n>>m;
    int cnt=0;
    rep(i,1,n){
        cin>>s[i];
        s[i]=" "+s[i];
        rep(j,1,m)if(s[i][j]=='1')cnt++;
    }
    if(cnt==n*m){
        cout<<cnt-2<<"\n";
        return;
    }
    if(cnt<=1){
        cout<<cnt<<"\n";
        return;
    }
    int flag=0;
    rep(i,1,n)rep(j,1,m)flag|=check(i,j);
    if(flag)cout<<cnt<<"\n";
    else cout<<cnt-1<<"\n";
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
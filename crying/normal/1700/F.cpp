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
int n;
int a[2][MAXN],b[2][MAXN],cnta,cntb;
ll ans;
int main(){
    cin>>n;
    rep(i,0,1)rep(j,1,n)cin>>a[i][j],cnta+=a[i][j];
    rep(i,0,1)rep(j,1,n)cin>>b[i][j],cntb+=b[i][j];
    if(cnta!=cntb){cout<<-1;return 0;}
    int d1=0,d2=0;
    rep(i,1,n){
        d1+=a[0][i];d1-=b[0][i];
        d2+=a[1][i];d2-=b[1][i];
        int step=min(abs(d1),abs(d2));
        if(d1>0 && d2<0)d1-=step,d2+=step,ans+=step;
        else if(d1<0 && d2>0)d1+=step,d2-=step,ans+=step;
        ans+=abs(d1)+abs(d2);
    }
    cout<<ans;
    return 0;
}
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
const int MAXN=2510;
int n,a[MAXN][MAXN],m;
int d[MAXN][MAXN];
array<int,3>val[MAXN*MAXN];

bitset<MAXN>rvalid[MAXN],cvalid[MAXN],rrest[MAXN],crest[MAXN],tmp;
void cover(int x,int y,int v){
    d[x][y]=v;
    rrest[x][y]=crest[y][x]=0;
}
inline int read()
{
    int x=0;
    bool flag=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            flag=0;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    return (flag?x:~(x-1));
}
int main(){
    n=read();
    rep(i,1,n){
        rep(j,1,n)a[i][j]=read(),val[++m]={a[i][j],i,j};
    }
    rep(i,1,n)rep(j,1,n){
        int flag=1;
        rep(k,1,n)flag&=(a[i][j]<=max(a[i][k],a[k][j]));
    }
    rep(i,1,n)rep(j,1,n)rrest[i][j]=crest[i][j]=1;
    rep(i,1,n)rep(j,1,n){
        if(i==j && a[i][j]){cout<<"NOT MAGIC\n";return 0;}
        if(a[i][j]!=a[j][i]){cout<<"NOT MAGIC\n";return 0;}
    }

    sort(val+1,val+1+m);

    rep(i,1,m){
        int x=val[i][1],y=val[i][2],v=val[i][0];
        rvalid[y][x]=cvalid[x][y]=1;
        //as a column element
        tmp=crest[y] & rvalid[x];
        for(int p=tmp._Find_first();p!=tmp.size();p=tmp._Find_next(p)){
            cover(p,y,v);
        }
        //as a row element
        tmp=rrest[x] & cvalid[y];
        for(int p=tmp._Find_first();p!=tmp.size();p=tmp._Find_next(p)){
            cover(x,p,v);
        }
    }
    rep(i,1,n)rep(j,1,n)if(a[i][j]>d[i][j]){
        cout<<"NOT MAGIC\n";return 0;
    }

    cout<<"MAGIC";
    return 0;
}
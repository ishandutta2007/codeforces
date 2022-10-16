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
const int MAXN=510,INF=1e9;
int n,k,a[MAXN][MAXN],cnt;
set<int>s;
vector<array<int,2> >occ[MAXN*MAXN];
int d[MAXN][MAXN];
int minx[MAXN*MAXN],miny[MAXN*MAXN],maxx[MAXN*MAXN],maxy[MAXN*MAXN];
void upd(int x1,int y1,int x2,int y2){
    d[x1][y1]++;
    d[x2+1][y1]--;
    d[x1][y2+1]--;
    d[x2+1][y2+1]++;
}
void calc(int len){
    rep(i,1,n-len+1)rep(j,1,n-len+1)d[i][j]=d[i][j]+d[i-1][j]+d[i][j-1]-d[i-1][j-1];
}
void check(){
    rep(i,1,n)rep(j,1,n)occ[a[i][j]].push_back({i,j});
    rep(col,1,n*n){
        minx[col]=miny[col]=INF;
        maxx[col]=maxy[col]=-INF;
        for(auto p:occ[col]){
            minx[col]=min(minx[col],p[0]);
            maxx[col]=max(maxx[col],p[0]);
            miny[col]=min(miny[col],p[1]);
            maxy[col]=max(maxy[col],p[1]);
        }
    }

    rep(len,1,n){
        memset(d,0,sizeof d);

        rep(col,1,n*n){
            if(occ[col].empty())continue;
            int a=minx[col],b=miny[col],c=maxx[col],d=maxy[col];
            int minx,miny,maxx,maxy;
            minx=max(1,c-len+1);maxx=min(a,n-len+1);
            miny=max(1,d-len+1);maxy=min(b,n-len+1);
            if(minx<=maxx && miny<=maxy)upd(minx,miny,maxx,maxy);
        }

        calc(len);
        rep(i,1,n-len+1)rep(j,1,n-len+1)if(d[i][j]==cnt-k || d[i][j]==cnt-k+1){
            cout<<"1\n";
            exit(0);
        }
    } 
}
int main(){
    cin>>n>>k;
    rep(i,1,n){
        rep(j,1,n){
            cin>>a[i][j];
            s.insert(a[i][j]);
        }
    }
    cnt=s.size();
    if(cnt<=k){
        cout<<k-cnt<<"\n";
        return 0;
    }
    check();
    cout<<"2";

    return 0;
}
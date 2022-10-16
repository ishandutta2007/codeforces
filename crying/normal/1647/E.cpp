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
int n,p[MAXN],a[MAXN],lst[MAXN],b[MAXN],steps,fa[MAXN],tag[MAXN],cnt;
int f[MAXN][30];
vector<int>endpos[MAXN];
int leap(int u,int steps){
    per(j,29,0){
        if(steps>=(1<<j)){
            u=f[u][j];
            steps-=(1<<j);
        }
    }
    return u;
}
int main(){
    cin>>n;
    rep(i,1,n){
        cin>>p[i];
        fa[p[i]]++;
        f[i][0]=p[i];
    }
    rep(j,1,29)rep(i,1,n)f[i][j]=f[f[i][j-1]][j-1];
    int flag=0;
    rep(i,1,n){
        cin>>a[i];
        if(a[i]>n)flag=1;
    }
    if(!flag){
        rep(i,1,n)cout<<a[i]<<' ';
        return 0;  
    }
    rep(i,1,n)if(!fa[i])cnt++;
    rep(i,1,n){
        if(a[i]>n&&!fa[i]){
            steps=(a[i]-n+cnt-1)/cnt;
        }
    }
    rep(i,1,n){
        lst[i]=leap(i,steps);
    }
    rep(i,1,n){endpos[lst[i]].push_back(i);}
    rep(i,1,n){sort(endpos[i].begin(),endpos[i].end(),greater<int>());}
    rep(i,1,n){
        if(a[i]<=n){
            tag[a[i]]=i;
            b[endpos[i].back()]=a[i];
            endpos[i].pop_back();
        }
    } 
    set<int>pos;pos.clear();
    rep(i,1,n){
        if(tag[i]){
            int idx=tag[i];
            for(auto u:endpos[idx])pos.insert(u);
        }else{
            int p=*pos.begin();
            b[p]=i;
            pos.erase(p);
        }
    }
    rep(i,1,n)cout<<b[i]<<' ';
    return 0;
}
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
const int MAXN=2010;
int n,E[MAXN][MAXN];
int fact[10];
int deg[MAXN];
int ans=1e9,sum;
void flip(int u,int v){
    deg[u]-=E[u][v];deg[v]-=E[v][u];
    E[u][v]^=1;E[v][u]^=1;
    deg[u]+=E[u][v];deg[v]+=E[v][u];
}
void flip(int u){
    rep(v,1,n)if(u!=v)flip(u,v);
}
int bucket[MAXN];
int check(){
    int sum=0,cnt=0,cur=0;
    memset(bucket,0,sizeof bucket);
    rep(i,1,n){
        bucket[deg[i]]++;
    }
    while(cnt+1<n){
        if(!bucket[cur])cur++;
        else{
            bucket[cur]--;
            cnt++;
            sum+=cur;
            if(sum==cnt*(cnt-1)/2){
                return 0;
            }
        }
    }
    return 1;
}
int check(int mask){
    rep(i,0,n-1)if(mask>>i&1)flip(i+1);
    int res=check();
    rep(i,0,n-1)if(mask>>i&1)flip(i+1);
    return res;
}
int main(){
    fact[0]=1;rep(i,1,9)fact[i]=fact[i-1]*i;
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)rep(j,1,n){
        char ch;cin>>ch;
        E[i][j]=ch-'0';
        deg[i]+=E[i][j];
    }
    if(n<=6){
        rep(mask,0,(1<<n)-1){
            if(check(mask)){
                ans=min(ans,__builtin_popcount(mask));
            }
        }
        rep(mask,0,(1<<n)-1){
            if(check(mask)){
                int cnt=__builtin_popcount(mask);
                if(cnt==ans){
                    sum+=fact[cnt];
                }
            }
        }
    }else{
        if(check()){
            cout<<"0 1";
            return 0;
        }
        ans=1;
        rep(i,1,n){
            flip(i);
            if(check())sum++;
            flip(i);    
        }
    }
    if(ans==1e9)cout<<"-1";
    else cout<<ans<<" "<<sum;

    return 0;
}
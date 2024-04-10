#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e3+10;
int T,n,m;
char s[MAXN][MAXN],t[MAXN];
int f[MAXN];
ppi bucket[27*27*27],pre[MAXN];
vector<ppi>ans;
void solve(int i){
    if(i==0)return;
    ans.pb(pre[i]);
    int len=pre[i].se.se-pre[i].se.fr+1;
    solve(i-len);
}
void solve(){
    scanf("%d%d",&n,&m);
    rep(i,1,n)scanf("%s",s[i]+1);
    scanf("%s",t+1);
    f[0]=1;
    rep(i,1,m)f[i]=0,pre[i]=mp(0,mp(0,0));
    rep(len,2,3){
        rep(i,1,n){
            rep(j,1,m-len+1){
                int val=0;
                rep(x,j,j+len-1){
                    val=val*27+(s[i][x]-'0'+1);
                }
                bucket[val]=mp(i,mp(j,j+len-1));
            }
        }
    }
    rep(i,2,m){
        rep(len,2,min(i,3)){
            if(f[i-len]==0)continue;
            int val=0;
            rep(x,i-len+1,i){
                val=val*27+(t[x]-'0'+1);
            }
            if(bucket[val].fr==0)continue;
            else{
                f[i]=1;
                pre[i]=bucket[val];
                break;
            }
        }
    }
    rep(len,2,3){
        rep(i,1,n){
            rep(j,1,m-len+1){
                int val=0;
                rep(x,j,j+len-1){
                    val=val*27+(s[i][x]-'0'+1);
                }
                bucket[val]=mp(0,mp(0,0));
            }
        }
    }
    if(f[m]){
        ans.clear();
        solve(m);
        reverse(ans.begin(),ans.end());
        printf("%d\n",(int)ans.size());
        for(auto p:ans)printf("%d %d %d\n",p.se.fr,p.se.se,p.fr);
    }else{
        printf("-1\n");
    }
}
int main(){
    scanf("%d",&T);
    while(T--){solve();}
    return 0;
}
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
const int MAXN=2e5+10;
int T,n,m,k,tag[MAXN];
vector<int>ret[MAXN];
void solve(){
    cin>>n>>m>>k;
    int cnt=n%m;
    int a=n/m,b=(n+m-1)/m,cur=0;
    rep(i,0,n)tag[i]=0;
    rep(i,1,k){
        rep(j,1,m)ret[j].clear();
        rep(j,1,cnt){
            rep(k,1,b){
                ret[j].push_back(cur);
                tag[cur]=i;
                cur=(cur+1)%n;
            }
        }
        int cur2=0;
        while(tag[cur2]==i)cur2=(cur2+1)%n;
        rep(j,cnt+1,m){
            rep(k,1,a){
                ret[j].push_back(cur2);
                cur2=(cur2+1)%n;
                while(tag[cur2]==i)cur2=(cur2+1)%n;
            }
        }
        rep(j,1,m){
            int sz=ret[j].size();
            printf("%d ",sz);
            for(auto u:ret[j])printf("%d ",u+1);
            printf("\n");
        }
    }
    printf("\n");
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
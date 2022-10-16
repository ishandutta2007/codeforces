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
const int MAXN=(1<<16)+10;
int t,n,k,rev[MAXN];
vector<pi>ret;
void solve(){
    cin>>n>>k;
    rep(i,0,n-1)rev[i]=(n-1)^i;
    if(k==n-1 && n==4){
        printf("-1\n");return;
    }
    if (n-1==k) {
        printf("%d %d\n",n-1,n-2);
        printf("%d %d\n",0,1);
        printf("%d %d\n",3,n-1-3+1);
        printf("%d %d\n",2,n-1-3);
        for (int i=4;i<n/2;i++) {
            printf("%d %d\n",i,n-i-1);
        }
        return;
    }
    ret.clear();
    rep(i,0,n-1){
        if(i==0){
            ret.pb(mp(0,rev[k]));
        }else if(i==k){
            ret.pb(mp(k,n-1));
        }else if(i!=rev[k] && i!=n-1){
            if(i<rev[i]){
                ret.pb(mp(i,rev[i]));
            }
        }
    }
    rep(i,0,n/2-1)printf("%d %d\n",ret[i].fr,ret[i].se);
}
int main(){
    cin>>t;
    while(t--)solve();

    return 0;
}
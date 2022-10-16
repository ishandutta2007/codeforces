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
int T,n,a[MAXN];
int suf[MAXN];
int bucket[MAXN],cur;
vector<int>ret;
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    ret.clear();
    cur=0;
    per(i,n,1){
        bucket[a[i]]++;
        while(bucket[cur])cur++;
        suf[i]=cur;
    }
    rep(i,1,n)bucket[a[i]]=0;
    for(int l=1,r;l<=n;l=r+1){
        ret.pb(suf[l]);
        cur=0;
        r=l-1;
        while(1){
            r++;
            bucket[a[r]]++;
            while(bucket[cur])cur++;
            if(cur==suf[l])break;
        }
       // printf("[%d,%d]\n",l,r);
        rep(j,l,r)bucket[a[j]]=0;
    }
    printf("%d\n",(int)ret.size());
    for(auto u:ret)printf("%d ",u);printf("\n");
    rep(i,1,n)bucket[a[i]]=0;
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
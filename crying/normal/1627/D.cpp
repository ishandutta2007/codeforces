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
const int MAXN=1e6+10,LIM=1e6;
int n,a[MAXN],bucket[MAXN],ans;
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]),bucket[a[i]]=1;
    rep(i,1,LIM){
        int ret=0;
        if(bucket[i])continue;
        rep(j,2,LIM){
            if(i*j>LIM)break;
            if(!bucket[i*j])continue;
            if(!ret)ret=j;
            else ret=gcd(ret,j);
            if(ret==1)break;
        }
        if(ret==1){
            ans++;
        }
    }
    printf("%d",ans);

    return 0;
}
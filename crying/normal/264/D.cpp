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
const int MAXN=1e6+10;
int n,m;
char s[MAXN],t[MAXN];
int a[MAXN],b[MAXN];
int sum[9][MAXN];
int qry(int* s,int l,int r){
    if(l>r)return 0;
    if(l==0)return s[r];
    return s[r]-s[l-1];
}
ll ans;
int main(){
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    rep(i,1,n)a[i]=s[i]%3;
    rep(i,1,m)b[i]=t[i]%3;
    rep(i,2,n){
        rep(j,0,8)sum[j][i]=sum[j][i-1];
        sum[a[i-1]*3+a[i]][i]++;
    }
    for(int i=1,l=1,r=1;i<=m;i++){
        //r
        while(r+1<=n && a[r]!=b[i])r++;
    //    printf("i:%d [%d,%d]\n",i,l,r);
        ans+=(r-l+1);
        if(i>1 && b[i]!=b[i-1])ans-=qry(sum[b[i]*3+b[i-1]],l,r);
        if(a[l]==b[i]){
            l++;
            if(l>n)break;
        }
        if(r<n)r++;
    }
    printf("%lld",ans);
    return 0;
}
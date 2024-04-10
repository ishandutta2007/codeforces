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
int n,a[MAXN];
int logn[MAXN],st[20][MAXN],l[MAXN];
int gcd(int a,int b){if(!b)return a;return gcd(b,a%b);}
int qry(int l,int r){int len=logn[r-l+1];return gcd(st[len][l],st[len][r-(1<<len)+1]);}
int main(){
    logn[0]=-1;rep(i,1,2e5)logn[i]=logn[i>>1]+1;
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]),st[0][i]=a[i];
    rep(i,1,19)rep(j,1,n){
        if(j+(1<<i)-1>n)break;
        st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
    }
    rep(r,1,n){
        int L=1,R=r;
        while(L<=R){
            int mid=(L+R)>>1;
            int val=qry(mid,r);
            if(val==r-mid+1){
                l[r]=mid;
                break;
            }else if(val>r-mid+1){
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
    }
    int ans=0,pre=0;
    rep(r,1,n){
        if(l[r] && pre<l[r])ans++,pre=r;
        printf("%d ",ans);
    }
    return 0;
}
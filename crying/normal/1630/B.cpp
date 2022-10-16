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
int t,n,k,a[MAXN],bucket[MAXN];
int qry(int*s ,int l,int r){
    if(l>r)return 0;
    if(l==0)return s[r];
    return s[r]-s[l-1];
}
void solve(){
    cin>>n>>k;
    rep(i,1,n)cin>>a[i];rep(i,1,n)bucket[i]=0;
    rep(i,1,n)bucket[a[i]]++;
    rep(i,1,n)bucket[i]+=bucket[i-1];
    int l=-1,r=n+1;
    rep(i,1,n){
        int L=i,R=n,ret=-1;
        while(L<=R){
            int mid=(L+R)>>1;
            if(qry(bucket,i,mid)>=n-qry(bucket,i,mid)+k){
                ret=mid;R=mid-1;
            }else{
                L=mid+1;
            }
        }
        if(ret!=-1){
            if(r-l+1 > ret-i+1){
                l=i,r=ret;
            }
        }
    }
    printf("%d %d\n",l,r);
    int lp=1,cnt=0,cnt1=0;
    rep(i,1,k){
        int rp=lp-1;
        while(cnt1<=cnt-cnt1){
            rp++;
            cnt++;
            if(a[rp]>=l && a[rp]<=r){
                cnt1++;
            }
        }
        cnt=cnt1=0;
        if(i!=k){
            printf("%d %d\n",lp,rp);
            lp=rp+1;
        }else{
            printf("%d %d\n",lp,n);
            break;
        }
    }
}
int main(){
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
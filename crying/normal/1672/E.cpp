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
const int MAXN=2010,INF=1e9;
int n,ans=INF;
int qry(int x){
    cout<<"? "<<x<<endl;
    int ret;cin>>ret;
    return ret;
}
int main(){
    cin>>n;
    int l=1,r=5e6,ret=0;
    while(l<=r){
        int mid=(l+r)>>1;
        int val=qry(mid);
        if(val==1){
            ret=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    ans=ret;
    rep(i,2,n){
        int w=ret/i;
        if(qry(w)==i){
            ans=min(ans,w*i);
        }
    }
    cout<<"! "<<ans<<endl;
    return 0;
}
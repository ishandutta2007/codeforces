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
const int MAXN=1e6+10;
int n,a[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,a[n]){
        if(1ll*(i+1)*(i+1)<=a[1])continue;
        ll k=max(0LL,1ll*i*i-a[1]); //all add k
        int j=i;
        while(1){
            if(1ll*j*j>a[n]+k)break;
            j++;
        }
        j--;
        ll L=0,R=1ll*i*i+i-a[1];
        rep(x,i,j){
            //x
            int pos1=upper_bound(a+1,a+1+n,1ll*x*x+x-k)-a;
            int pos2=pos1-1;
            if(1<=pos1 && pos1<=n && a[pos1]+k<1ll*(x+1)*(x+1) && a[pos1]+k>1ll*x*x+x){
                L=max(L,1ll*(x+1)*(x+1)-a[pos1]-k);
            }
            if(1<=pos2 && pos2<=n && a[pos2]+k>=1ll*x*x && a[pos2]+k<=1ll*x*x+x){
                R=min(R,1ll*x*x+x-a[pos2]-k);
            }
        }
        if(L>R)continue;
        cout<<k+L<<endl;exit(0);
    }

    return 0;
}
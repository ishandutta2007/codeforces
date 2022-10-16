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
const int MAXN=510;
int n,k,r,c,T;
int ans[MAXN];
void solve(){
    cin>>n>>k>>r>>c;
    r--,c--;
    r%=k;c%=k;
    memset(ans,0,sizeof ans);
    ans[r]=c;
    rep(i,r+1,k-1){
        ans[i]=ans[i-1]+1;
        if(ans[i]==k)ans[i]=0;
    }
    if(r!=0){
        ans[0]=ans[k-1]+1;if(ans[0]==k)ans[0]=0;
        rep(i,1,r-1){
            ans[i]=ans[i-1]+1;
            if(ans[i]==k)ans[i]=0;
        }
    }
    rep(i,0,n-1){
        rep(j,0,n-1){
            if(j%k==ans[i%k])cout<<"X";
            else cout<<".";
        }
        cout<<"\n";
    }
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
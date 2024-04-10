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
const int MAXN=2e5+10;
int T,m,n,a[MAXN];
int cnt1,cnt2,cnt3;
map<ll,int>f;
void solve(){
    cin>>m;
    n=0;
    cnt1=cnt2=cnt3=0;
    while(m--){
        int num;cin>>num;
        if(num>0){
            cnt1++;
            if(cnt1<=3)a[++n]=num;
        }else if(num==0){
            cnt3++;
            if(cnt3<=3)a[++n]=num;
        }else{
            cnt2++;
            if(cnt2<=3)a[++n]=num;
        }
    }
    if(cnt1>=3 || cnt2>=3){
        cout<<"NO\n";return;
    }
    f.clear();
    rep(i,1,n)f[a[i]]=1;
    rep(i,1,n)rep(j,i+1,n)rep(k,j+1,n){
        ll val=0ll+a[i]+a[j]+a[k];
        if(f.find(val)==f.end()){
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";

}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}
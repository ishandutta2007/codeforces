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
const int MAXN=1e4+10;
int T,n,a[MAXN];
int b[MAXN];
map<int,int>f;
void solve(int l,int r){
    if(l==r){
        cout<<"! "<<l<<endl;return;
    }
    int mid=(l+r)>>1;
    cout<<"? "<<l<<' '<<mid<<endl;
    f.clear();
    int num=0;
    rep(i,l,mid)if(a[i])num++;
    rep(i,l,mid)cin>>b[i],f[b[i]]=1;
    int cnt=0;
    rep(i,l,mid)if(a[i]){
        if(f.find(i)==f.end()){
            cnt++;
            a[i]=0;
        }
    }
    rep(i,l,mid)if(b[i]>mid && b[i]<=r)a[b[i]]=0;
    if(even(cnt)){
        if(odd(num))solve(l,mid);
        else solve(mid+1,r);
    }else{
        if(even(num))solve(l,mid);
        else solve(mid+1,r);
    }
}
void solve(){
    cin>>n;
    rep(i,1,n)a[i]=1;
    solve(1,n);
}
int main(){
    cin>>T;
    while(T--)solve();

    

    return 0;
}
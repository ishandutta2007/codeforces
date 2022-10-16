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
const int MAXN=100,INF=2e9;
int T,n,a[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    if(odd(n)){
        cout<<"Mike\n";return;
    }
    int minx=INF,miny=INF,xpos=0,ypos=0;
    rep(i,1,n)if(odd(i)){
        if(a[i]<minx)minx=a[i],xpos=i;
    }else{
        if(a[i]<miny)miny=a[i],ypos=i;
    }
    if(minx<miny)cout<<"Joe\n";
    else if(minx>miny)cout<<"Mike\n";
    else{
        if(xpos<ypos)cout<<"Joe\n";
        else cout<<"Mike\n";
    }
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
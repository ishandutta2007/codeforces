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
ll T,a,b,c,d;
void solve(){
    cin>>a>>b>>c>>d;
    ll A=a*d,B=b*c;
    if(A==B){
        cout<<"0\n";
        return;
    }
    if(A==0 || B==0){
        cout<<"1\n";
        return;
    }
    if(A%B==0 || B%A==0){
        cout<<"1\n";
    }else{
        cout<<"2\n";
    }
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
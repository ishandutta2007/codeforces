#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=60;
int T,n,a[MAXN];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        if(n==3){
            printf("3 2 1\n");
            printf("1 3 2\n");
            printf("3 1 2\n");
            continue;
        }
        rep(i,1,n){
            per(j,i,1)cout<<j<<' ';
            per(j,n,i+1)cout<<j<<' ';
            cout<<'\n';
        }
    }

    return 0;
}
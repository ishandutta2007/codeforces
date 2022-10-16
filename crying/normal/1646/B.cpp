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
ll T,n,a[MAXN],s[MAXN];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        rep(i,1,n)cin>>a[i];
        sort(a+1,a+1+n);
        rep(i,1,n)s[i]=s[i-1]+a[i];
        if(odd(n)){
            if(s[n]-s[(n+1)/2]>s[(n+1)/2]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            if(s[n]-s[n/2+1]>s[n/2]){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

    return 0;
}
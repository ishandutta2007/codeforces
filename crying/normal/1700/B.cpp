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
const int MAXN=1e5+10;
int T,n;
char s[MAXN],t[MAXN];
void solve(){
    cin>>n>>(s+1);
    if(s[1]=='9'){
        int x=0;
        per(i,n,1){
            int num=(s[i]-'0')+x;
            x=0;
            if(num>1){
                t[i]='0'+(11-num);
                x=1;
            }else{
                t[i]='0'+(1-num);
            }
        }
        rep(i,1,n)putchar(t[i]);putchar('\n');
    }else{
        rep(i,1,n)putchar('0'+('9'-s[i]));
        putchar('\n');
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
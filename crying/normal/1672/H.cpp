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
int n,q,sum[2][MAXN];
char s[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q>>(s+1);
    rep(i,2,n){
        sum[0][i]=sum[0][i-1];
        sum[1][i]=sum[1][i-1];
        if(s[i]==s[i-1]){
            if(s[i]=='0')sum[0][i]++;
            else sum[1][i]++;
        }
    }
    rep(i,1,q){
        int l,r;cin>>l>>r;
        int ans=1+max(sum[0][r]-sum[0][l-1]-(s[l-1]==s[l] && s[l]=='0'),sum[1][r]-sum[1][l-1]-(s[l-1]==s[l] && s[l]=='1'));
        cout<<ans<<endl;
    }
    return 0;
}
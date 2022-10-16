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
const int MAXN=1e6+100;
char s[MAXN],t[MAXN];
int n,q,m,nxt[MAXN];
void getnxt(int i){
    int j=nxt[i-1];
    if(s[j+1]==s[i]){nxt[i]=j+1;return;}
    int pre=i-1;
    j=nxt[j];
    while(j && s[j+1]!=s[i]){
        if(pre-j==j-nxt[j]){
            int len=pre-j;
            j%=len;pre=j+len;
        }
        else pre=j,j=nxt[j];
    }
    if(s[j+1]==s[i])nxt[i]=j+1;
    else nxt[i]=0;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>(s+1);n=strlen(s+1);
    rep(i,2,n)getnxt(i);
    cin>>q;
    rep(i,1,q){
        cin>>(t+1);m=strlen(t+1);
        rep(j,1,m)s[n+j]=t[j];
        rep(j,n+1,n+m)getnxt(j);
        rep(j,n+1,n+m)cout<<nxt[j]<<" ";cout<<"\n";
    }

    return 0;
}
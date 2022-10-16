#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e4+10;
int n;
ll h[MAXN],pre[MAXN],suf[MAXN],ans;
int L[MAXN],R[MAXN],st[MAXN],top;
ll minn[MAXN][MAXN],tmp[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>h[i];
    rep(i,1,n){
        minn[i][i]=h[i];
        rep(j,i+1,n){
            minn[i][j]=minn[i][j-1];
            if(h[j]<minn[i][j])minn[i][j]=h[j];
        }
    }
    rep(i,1,n)tmp[i]=h[i];
    rep(i,1,n){
        tmp[i]=h[i];
        per(j,i-1,1)if(tmp[j]<=h[i])break;else tmp[j]=h[i];
        rep(j,1,i)pre[i]=max(pre[i],tmp[j]*(i-j+1));
        pre[i]=max(pre[i-1],pre[i]);
    }
    per(i,n,1){
        tmp[i]=h[i];
        rep(j,i+1,n)if(tmp[j]<=h[i])break;else tmp[j]=h[i];
        rep(j,i,n)suf[i]=max(suf[i],tmp[j]*(j-i+1));
        suf[i]=max(suf[i+1],suf[i]);
    }
    rep(i,0,n)ans=max(ans,pre[i]+suf[i+1]);    
    top=0;rep(i,1,n){
        while(top&&h[st[top]]>=h[i])top--;
        if(top)L[i]=st[top];
        L[i]++;st[++top]=i;R[i]=n+1;
    }
    top=0;per(i,n,1){
        while(top&&h[st[top]]>=h[i])top--;
        if(top)R[i]=st[top];
        R[i]--;st[++top]=i;
    }
    rep(i,1,n){
        int l=L[i],r=R[i]; //[l,r]
        per(j,n,r+1)tmp[j]=max(minn[l][j]*(j-l+1),tmp[j+1]);
        rep(j,1,l-1)tmp[j]=max(minn[j][r]*(r-j+1),tmp[j-1]);
        int p=n;ll hl=h[i];
        int p2=r;
        per(j,l-1,1){
            if(h[j]<hl)hl=h[j];
            while(p>r&&minn[l][p]+hl<h[i])p--;
            ans=max(ans,hl*(r-j+1)+tmp[p+1]);
            ans=max(ans,hl*(r-j+1)+(h[i]-hl)*(p-l+1));
            while(p2+1<=n&&h[p2+1]>=hl)p2++;
            ans=max(ans,hl*(l-j+p2-r)+h[i]*(r-l+1));
        }
        p=1;p2=l;hl=h[i];
        rep(j,r+1,n){
            if(h[j]<hl)hl=h[j];
            while(p<l&&minn[p][r]+hl<h[i])p++;
            ans=max(ans,hl*(j-l+1)+tmp[p-1]);
            ans=max(ans,hl*(j-l+1)+(h[i]-hl)*(r-p+1));
            while(p2-1>=1&&h[p2-1]>=hl)p2--;
            ans=max(ans,hl*(j-r+l-p2)+h[i]*(r-l+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}
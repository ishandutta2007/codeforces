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
const int MAXN=3e5+10,INF=1e9;
int T,n,a[MAXN],ans;
int minL[MAXN],minR[MAXN],maxL[MAXN],maxR[MAXN];
int st1[MAXN],st2[MAXN],top1,top2;
struct Seg{
    int minn[MAXN<<2];
    void pushup(int x){
        minn[x]=min(minn[lc(x)],minn[rc(x)]);
    }
    void build(int x,int l,int r,int* a){
        if(l==r){
            minn[x]=a[l];return;
        }
        int mid=(l+r)>>1;
        build(lc(x),l,mid,a);
        build(rc(x),mid+1,r,a);
        pushup(x);
    }
    int qry(int x,int l,int r,int ql,int qr){
        if(ql<=l && qr>=r)return minn[x];
        int mid=(l+r)>>1,ret=INF;
        if(ql<=mid)ret=min(ret,qry(lc(x),l,mid,ql,qr));
        if(qr>mid)ret=min(ret,qry(rc(x),mid+1,r,ql,qr));
        return ret;
    }
}seg1,seg2;
void solve(){
    cin>>n;ans=0;
    rep(i,1,n)cin>>a[i];
    top1=top2=0;
    rep(i,1,n)minL[i]=maxL[i]=0,minR[i]=maxR[i]=n+1;
    rep(i,1,n){
        while(top1 && a[st1[top1]]>a[i])top1--;
        while(top2 && a[st2[top2]]<a[i])top2--;
        if(top1)minL[i]=st1[top1];
        if(top2)maxL[i]=st2[top2];
        st1[++top1]=i;
        st2[++top2]=i;
    }
    top1=top2=0;
    per(i,n,1){
        while(top1 && a[st1[top1]]>a[i])top1--;
        while(top2 && a[st2[top2]]<a[i])top2--;
        if(top1)minR[i]=st1[top1];
        if(top2)maxR[i]=st2[top2];
        st1[++top1]=i;
        st2[++top2]=i;
    }
    seg1.build(1,1,n,minL);
    seg2.build(1,1,n,maxL);
    int cur=1;
    while(cur<n){
        int nxt=cur+1;
        int L=cur+1,R=minR[cur]-1,ret=0;
        while(L<=R){
            int mid=(L+R)>>1;
            int val=seg2.qry(1,1,n,mid,minR[cur]-1);
            if(val<=cur){
                ret=mid;
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        nxt=max(nxt,ret);
        L=cur+1;R=maxR[cur]-1,ret=0;
        while(L<=R){
            int mid=(L+R)>>1;
            int val=seg1.qry(1,1,n,mid,maxR[cur]-1);
            if(val<=cur){
                ret=mid;
                L=mid+1;
            }else{
                R=mid-1;
            }
        }
        nxt=max(nxt,ret);
        cur=nxt;ans++;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}
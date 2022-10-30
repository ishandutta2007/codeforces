#include <bits/stdc++.h>
using namespace std;



int n,sz;
int p[200005];
int len[200005];
int nxt[200005],rg[200005],s[200005];
int t[800005];
int sz2[200005];
int dp1[200005][20];
int dp2[200005][20];
int dp3[200005][20];
void update(int x){
    int xx=x+sz-1;
    t[xx]=x;
    xx>>=1;
    while (xx) {
        int ll=t[xx+xx];
        int rr=t[xx+xx+1];
        if (!rr) t[xx]=ll;
        else t[xx] = ( rg[rr]>=rg[ll] ? rr : ll );
        xx>>=1;
    }
}
int get_max(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || ll>rr || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    int x1=get_max(l,mid,ll,rr,x+x),x2=get_max(mid+1,r,ll,rr,x+x+1);
    if (!x2) return x1;
    else if (!x1) return x2;
    else return (rg[x2]>=rg[x1] ? x2 : x1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>p[i]>>len[i];
    }
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=n-1;i>0;--i) {
        if (p[i]+len[i]<p[i+1]) {
            rg[i]=len[i]+p[i];
            nxt[i]=i+1;
            update(i);
            continue;
        }
        int l=i+1;
        int r=n;
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (p[mid]<=p[i]+len[i]) l=mid;
            else r=mid;
        }
        if (p[r]<=p[i]+len[i]) l=r;
        if (l==n) {
            rg[i]=len[i]+p[i];
            nxt[i]=n+1;
            update(i);
            continue;
        }
        int pos=get_max(1,sz,i+1,l,1);
        rg[i]=max(p[i]+len[i],rg[pos]);
        nxt[i]=max(l+1,nxt[pos]);
        update(i);
    }
    rg[n]=len[n]+p[n];
    nxt[n]=n+1;
    for (int i=2;i<=n;++i)
        sz2[i]=sz2[i/2]+1;
    for (int i=1;i<=n;++i) {
        dp1[i][0]=rg[i];
        dp2[i][0]=nxt[i];
        dp3[i][0]=max(0,p[nxt[i]]-rg[i]);
    }
    for (int i=1;i<=sz2[n];++i){
    for (int j=1;j<=n;++j) {
        dp2[j][i]=dp2[dp2[j][i-1]][i-1];
        dp3[j][i]=dp3[dp2[j][i-1]][i-1]+dp3[j][i-1];
    }
    }
    int m;
    cin>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        int ans=0;
        for (int j=sz2[n];j>=0;--j) if (dp2[x][j] && dp2[x][j]<y){
            ans+=dp3[x][j];
            x=dp2[x][j];
        }
        if (rg[x]<p[y]) ans+=dp3[x][0];
        cout<<ans<<'\n';
    }
}
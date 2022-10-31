#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define ll long long
#define pb push_back
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define sit set<int>::iterator
using namespace std;
const int N=2e6+6;
int p[N],q[N],mx[N],ad[N];
void add(int rt,int l,int r,int ql,int qr,int d){
    if (r<ql||qr<l) return;
    if (ql<=l&&r<=qr){ ad[rt]+=d,mx[rt]+=d; return; }
    int m=l+r>>1;
    add(rt<<1,l,m,ql,qr,d),add(rt<<1|1,m+1,r,ql,qr,d);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1])+ad[rt];
}
int read(){
    int c=0,f=1; char ch=getchar();
    while ((ch<'0'||'9'<ch)&&ch!='-') ch=getchar();
    if (ch=='-') f=-1,ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c*f;
}
int main(){
    int n=read();
    for (int i=1;i<=n;++i) p[read()]=i;
    for (int i=1;i<=n;++i) q[i]=read();
    int ans=n; cout<<n<<" ";
    add(1,1,n,1,p[n],1);
    for (int i=1;i<n;++i){
        add(1,1,n,1,q[i],-1);
        while (mx[1]<=0&&ans)
            --ans,add(1,1,n,1,p[ans],1);
        if (ans==0) printf("1 ");
        else{
            add(1,1,n,1,p[ans],-1),++ans;
            printf("%d ",ans-1);
        }
    }
    return 0;
}
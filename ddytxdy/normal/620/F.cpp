#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define LL long long
#define pii pair<int,int>
using namespace std;
const int N=5e4+50,M=2e6+50;
int n,m,a[N],blo[N],B,sum[M],rt1=1,rt2=2,ch[M][2],mn[M],mx[M],cnt=2,ans,out[N],rr[N];
pair<int*,int> oper[M];int tp;
struct node{
    int l,r,id;
    bool friend operator <(node a,node b){
        return blo[a.l]^blo[b.l]?blo[a.l]<blo[b.l]:a.r<b.r;
    }
}q[N];
void sav(int *x){
    oper[++tp]=mp(x,*x);
}
void insert1(int x,int d){
    int p=rt1;
    if(d<mn[p])sav(&mn[p]),mn[p]=d;
    for(int i=19;~i;i--){
        int c=x>>i&1;
        if(!ch[p][c])sav(&ch[p][c]),sav(&cnt),ch[p][c]=++cnt;
        p=ch[p][c];
        if(d<mn[p])sav(&mn[p]),mn[p]=d;
    }
}
void insert2(int x,int d){
    int p=rt2;
    if(d>mx[p])sav(&mx[p]),mx[p]=d;
    for(int i=19;~i;i--){
        int c=x>>i&1;
        if(!ch[p][c])sav(&ch[p][c]),sav(&cnt),ch[p][c]=++cnt;
        p=ch[p][c];
        if(d>mx[p])sav(&mx[p]),mx[p]=d;
    }
}
int ask1(int x,int d){
    int ret=0,p=rt1;
    for(int i=19;~i;i--){
        int c=x>>i&1;
        if(mn[ch[p][c^1]]<d)p=ch[p][c^1],ret^=1<<i;
        else p=ch[p][c];
    }
    return ret;
}
int ask2(int x,int d){
    int ret=0,p=rt2;
    for(int i=19;~i;i--){
        int c=x>>i&1;
        if(mx[ch[p][c^1]]>d)p=ch[p][c^1],ret^=1<<i;
        else p=ch[p][c];
    }
    return ret;
}
void add(int x){
    insert1(sum[a[x]-1],a[x]-1);
    insert2(sum[a[x]],a[x]);
    int d=max(ask1(sum[a[x]],a[x]),ask2(sum[a[x]-1],a[x]-1));
    if(d>ans)sav(&ans),ans=d;
}
void undo(int x){
    while(tp>x)*oper[tp].first=oper[tp].second,tp--;
}
int main(){
    scanf("%d%d",&n,&m);B=max(n/sqrt(m),1.0);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),
        blo[i]=(i-1)/B+1,rr[blo[i]]=i;
    for(int i=1;i<=m;i++)
        scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+m+1);
    for(int i=1;i<M;i++)
        sum[i]=sum[i-1]^i;
    memset(mn,0x3f,sizeof(mn));
    for(int i=1,L,R;i<=m;i++){
        // if(q[i].l==2&&q[i].r==5)
            // printf("%d %d\n",blo[q[i].l],blo[q[i].r]);
        if(blo[q[i].l]!=blo[q[i-1].l]){
            undo(0);
            L=rr[blo[q[i].l]]+1;R=L-1;
        }
        if(blo[q[i].l]==blo[q[i].r]){
            for(int j=q[i].l;j<=q[i].r;j++)
                add(j);
            out[q[i].id]=ans;
            undo(0);
            continue;
        }
        while(R<q[i].r)add(++R);
        int ttp=tp;
        while(L>q[i].l)add(--L);
        out[q[i].id]=ans;
        undo(ttp);
        L=rr[blo[q[i].l]]+1;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",out[i]);
    return 0;
}
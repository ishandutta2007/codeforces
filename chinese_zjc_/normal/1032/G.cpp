#include<bits/stdc++.h>

using namespace std;
const int N=3e5+10;
int n,a[N],b[N],c[N];
int Log[N];
int l[19][N],r[19][N];

struct rmq{
    int st[N][19],val[N];
    int type;
    inline int Max(int x,int y){
        return (val[x]<val[y])?y:x;
    }
    void build(int *b,int n,int _type){
        type=_type;
        for(int i=1;i<=n;i++) st[i][0]=i,val[i]=type*b[i];
        for(int j=1;j<=Log[n];j++){
            for(int i=1;i+(1<<j)-1<=n;i++)
                st[i][j]=Max(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
    inline int query(int l,int r){
        int k=Log[r-l+1];
        return Max(st[l][k],st[r-(1<<k)+1][k]);
    }
}rmq_l,rmq_r;

int main(){
    scanf("%d",&n);
    for(int i=2;i<=3*n;i++) Log[i]=Log[i>>1]+1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i+n]=a[i+n*2]=a[i];
    }
    if(n==1) return puts("0"),0;
    for(int i=1;i<=3*n;i++){
        b[i]=max(1,i-a[i]);
        c[i]=min(3*n,i+a[i]);
    }
    for(int i=0;i<=Log[3*n];i++) r[i][3*n]=3*n,l[i][1]=1;
    for(int i=1;i<=3*n;i++){
        l[0][i]=b[i];
        r[0][i]=c[i];
    }
    rmq_l.build(l[0],n*3,-1);rmq_r.build(r[0],n*3,1);
    for(int i=1;i<=Log[3*n];i++)
        for(int j=1;j<=3*n;j++){
            int posl=rmq_l.query(l[i-1][j],r[i-1][j]);  
            int posr=rmq_r.query(l[i-1][j],r[i-1][j]);
            l[i][j]=min(l[i-1][posl],l[i-1][posr]);
            r[i][j]=max(r[i-1][posl],r[i-1][posr]);
        }
    for(int j=n+1;j<=n*2;j++){
        int u=j,v=j;
        int ans=0;
        for(int i=Log[3*n];i>=0;i--){
            if(max(r[i][v],r[i][u])-min(l[i][u],l[i][v])+1>=n) continue;
            int nu=rmq_l.query(l[i][u],r[i][v]);
            int nv=rmq_r.query(l[i][u],r[i][v]);
            u=nu;v=nv; 
            ans+=1<<i;
        }
        ans++;
        printf("%d ",ans);
    }
    puts("");
    return 0;
}
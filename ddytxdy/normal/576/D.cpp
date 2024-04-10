#include<bits/stdc++.h>
using namespace std;
const int N=152;
int n,m,lim=1.5e9;bool fl[N],pp[N];
struct node{
    bitset<N>f[N];
    void clear(){for(int i=0;i<=n;i++)f[i].reset();}
    void init(){clear();for(int i=0;i<=n;i++)f[i][i]=1;}
    node operator *(const node &b)const{
        node c;c.clear();
        for(int i=0;i<=n;i++)
            for(int k=0;k<=n;k++)
                if(f[i][k])c.f[i]|=b.f[k];
        return c;
    }
}a;
struct node1{
    int x,y,z;
    bool friend operator <(node1 a,node1 b){return a.z<b.z;}
}e[N];
node power(node x,int y){
    node z;z.init();
    for(;y;y>>=1,x=x*x)if(y&1)z=z*x;
    return z;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    sort(e+1,e+m+1);a.f[0][n]=a.f[0][0]=1;fl[1]=1;
    if(e[1].z)puts("Impossible"),exit(0);
    for(int i=1,j=0;i<=m;i++){
        a.f[e[i].y][e[i].x]=1;
        int l=1,r=i<m?e[i+1].z-e[i].z:n;
        node p=power(a,r);bool ff=0;
        for(int j=1;j<=n;j++)ff|=fl[j]&(p.f[0][j]|p.f[n][j]);
        if(!ff){
            for(int j=1;j<=n;j++)pp[j]=0;
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    pp[j]|=fl[k]&p.f[j][k];
            for(int j=1;j<=n;j++)fl[j]=pp[j];
        }
        else{
            int ans=0;
            while(l<=r){
                int mid=(l+r)>>1;
                node p=power(a,mid);bool ff=0;
                for(int j=1;j<=n;j++)ff|=fl[j]&(p.f[0][j]|p.f[n][j]);
                ff?r=mid-1,ans=mid:l=mid+1;
            }
            printf("%d\n",ans+e[i].z);exit(0);
        }
    }
    puts("Impossible");
    return 0;   
}
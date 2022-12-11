#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50,inf=1e9;
int n,m,k,c[N],mm,l[N],r[N],id[N],f[N],mx,now,cnt[N],ans;
// struct node{
//     int l,r;
//     // bool friend operator <(node a,node b){return a.r<b.r;}
// }a[N];
vector<int>v[N];
void cmax(int &x,int y){y>x?x=y:0;}
int main(){
    scanf("%d%d%d",&n,&m,&k);mx=1<<k;
    for(int i=1;i<mx;i++)cnt[i]=cnt[i>>1]+(i&1);
    // for(int i=1;i<mx;i++)printf("%d ",cnt[i]);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l[i],&r[i]),r[i]++;
        c[i]=l[i],c[i+n]=r[i];
    }
    c[2*n+1]=1,c[2*n+2]=m;
    sort(c+1,c+n*2+3);mm=unique(c+1,c+n*2+3)-c-1;
    for(int i=1;i<=n;i++){
        l[i]=lower_bound(c+1,c+mm+1,l[i])-c;
        r[i]=lower_bound(c+1,c+mm+1,r[i])-c;
    }
    for(int i=1;i<=n;i++)for(int j=l[i];j<r[i];j++)v[j].push_back(i);
    memset(f,0xcf,sizeof(f));f[0]=0;
    for(int i=1;i<mm;i++){
        for(int j=0;j<k;j++)if(id[j]&&r[id[j]]<=i)now^=1<<j,id[j]=0;
        for(int j=0;j<mx;j++)if((j|now)!=now)cmax(f[j&now],f[j]),f[j]=-inf;
        for(int j=0;j<v[i].size();j++)if(l[v[i][j]]==i){
            for(int p=0;p<k;p++)if(!id[p]){
                for(int l=mx-1;~l;l--)f[l|1<<p]=f[l];
                id[p]=v[i][j],now|=1<<p;break;
            }
        }
        for(int j=0;j<mx;j++)f[j]+=(cnt[j]&1)*(c[i+1]-c[i]);
    }
    for(int i=0;i<mx;i++)cmax(ans,f[i]);
    cout<<ans;
    return 0;
}
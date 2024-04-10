#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mp make_pair
#define pb push_back
#define LL long long
// #define int long long
// #define pil pair<int,LL>
using namespace std;
const int N=1001000+50;LL inf=1e18;
int n1,n2,mat[N],vis[N],clk;
int id[N],pre[N],num,fr;LL ans[N],anss,mn[N],val[N],mx,D;
int a[N],cnt,n;LL b[N];
vector<int>v[N];
void rev(int x){
    int y=pre[x];
    if(mat[y])rev(mat[y]),ans[clk]+=b[y];
    mat[y]=x;mat[x]=y;
    ans[clk]-=b[y];
}
bool dfs(int x){
    if(vis[x]!=clk)val[x]+=D,vis[x]=clk;
    for(int i=0;i<v[x].size();i++){num++;
        int y=v[x][i];LL z=-b[x];
        if(vis[y]==clk)continue;
        if(val[x]-D+val[y]==z){
            vis[y]=clk;pre[y]=x;
            if(!mat[y]){rev(y);return 1;}
            else if(dfs(mat[y]))return 1;
        }
        else{
            LL d=val[x]-D+val[y]-z;
            if(d<mn[y])mn[y]=d,id[y]=x;
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);mx=-inf;int tim=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=1;j<=n;j++)
            b[++cnt]=1ll*a[i]*j;
    }
    sort(b+1,b+cnt+1);
    cnt=unique(b+1,b+cnt+1)-b-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int id=lower_bound(b+1,b+cnt+1,1ll*a[i]*j)-b;
            v[id].pb(i+cnt);
            mx=max(mx,-1ll*a[i]*j);
        }
    }
    n1=cnt;n2=n;//cout<<mx<<endl;
    // if(n1<n2)swap(n1,n2),swp=1;
    for(int i=1;i<=n1;i++)val[i]=mx;
    fr=1;
    for(clk=1;clk<=n1;clk++){
        bool fl=0;ans[clk]=ans[clk-1];
        for(int i=1;i<=n2;i++)
            mn[i+n1]=inf,id[i+n1]=0;
        //tim-=clock();
        // for(int i=fr;i<=n1;i++)
        //     if(!mat[i]&&vis[i]!=clk&&dfs(i)){fr=i+1;fl=1;break;}
        //tim+=clock();
        while(fr<=n1&&!dfs(fr)){
            bool fl=0;
            while(1){//num++;
                LL mm=inf,p=0;
                for(int i=1;i<=n2;i++)
                    if(vis[i+n1]!=clk&&mn[i+n1]<mm)
                        mm=mn[i+n1],p=i+n1;
                if(!p||!id[p]){fl=1;break;}
                // for(int i=1;i<=n1;i++)
                //     if(vis[i]==clk)val[i]-=mm;
                D+=mm;
                for(int i=1;i<=n2;i++)
                    if(vis[i+n1]==clk)val[i+n1]+=mm;
                    else mn[i+n1]-=mm;
                vis[p]=clk;pre[p]=id[p];
                if(!mat[p]){rev(p);break;}
                if(dfs(mat[p]))break;
            }//tim+=clock();
            if(!fl)break;
            fr++;
        }
        if(fr>n1)break;
        fr++;
        for(int i=1;i<=n1;i++)
            if(vis[i]==clk)val[i]-=D;
        D=0;
        // if(fl)continue;//tim-=clock();
        // for(int i=1;i<fr;i++)
        //     if(!mat[i]&&vis[i]!=clk)dfs(i);
        // fr=1;
    }
    // if(num>n*n)cout<<(1/0);
    // if(n==500)cout<<1.0*tim/CLOCKS_PER_SEC<<endl;
    // if(n==500)cout<<num<<endl;
    printf("%lld\n",-ans[clk-1]);
    // for(int i=1;i<=(swp?n2:n1);i++)
    //     printf("%d ",out[i]);
    return 0;
}
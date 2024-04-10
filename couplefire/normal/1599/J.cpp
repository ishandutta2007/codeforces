#include <bits/stdc++.h>
using namespace std;

int a[1000+5],b[1000+5];
vector<int> q[2];
map<pair<int,int>,int>mop;
int N,opt[1000+5],asum,acnt;

void dfs1(int id,int sum,int cnt){
    if (id==N/2+1){
        mop[make_pair(sum,cnt)]++;
        return;
    }
    dfs1(id+1,sum+b[id],cnt+1);
    dfs1(id+1,sum,cnt);
    dfs1(id+1,sum-b[id],cnt-1);
}

bool flag,vis[1000+5];

void dfs2(int id,int sum,int cnt,bool G){
    if (flag) return;
    if (id==N/2){
        if (mop[make_pair(-sum,-cnt)]||(G&&!sum&&!cnt)){
            asum=-sum;acnt=-cnt;
            flag=true;
            for (int i=N/2+1;i<=N;i++)
                if (opt[i]==1)
                    q[0].push_back(b[i]),vis[i]=true;
                else if (opt[i]==-1)
                    q[1].push_back(b[i]),vis[i]=true;
        }
        return ;
    }
    opt[id]=1;
    dfs2(id-1,sum+b[id],cnt+1,1);
    opt[id]=0;
    dfs2(id-1,sum,cnt,G);
    opt[id]=-1;
    dfs2(id-1,sum-b[id],cnt-1,1);
    opt[id]=0;
}

void dfs3(int id,int sum,int cnt){
    if (flag) return;
    if (id==N/2+1){
        if (sum!=asum||cnt!=acnt) return;
        flag=true;
        for (int i=1;i<=N/2;i++)
            if (opt[i]==1)
                q[0].push_back(b[i]),vis[i]=true;
            else if (opt[i]==-1)
                q[1].push_back(b[i]),vis[i]=true;
        return;
    }
    opt[id]=1;
    dfs3(id+1,sum+b[id],cnt+1);
    opt[id]=0;
    dfs3(id+1,sum,cnt);
    opt[id]=-1;
    dfs3(id+1,sum-b[id],cnt-1);
    opt[id]=0;
}

int main(){
    int n,m=0,i,j;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+n+1);
    for (i=2;i<=n;i++)
        if (b[i]==b[i-1]){
            printf("YES\n0 ");
            for (j=1;j<i;j++)
                printf("%d ",b[j]);
            for (j=i+1;j<=n;j++)
                printf("%d ",b[j]);
            printf("\n");
            return 0;
        }
    for (i=1;i<=n;i++)
        q[b[i]&1].push_back(b[i]);
    if (q[0].size()>=3){
        a[1]=(q[0][0]+q[0][1]+q[0][2])/2-q[0][0];
        a[2]=(q[0][0]+q[0][1]+q[0][2])/2-q[0][1];
        a[3]=(q[0][0]+q[0][1]+q[0][2])/2-q[0][2];
        m=3;
        for (i=3;i<q[0].size();i++)
            a[++m]=q[0][i]-a[1];
        for (i=0;i<q[1].size();i++)
            a[++m]=q[1][i]-a[1];
        printf("YES\n");
        for (i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return 0;
    }
    if (q[1].size()>=2&&q[0].size()){
        a[1]=(q[0][0]+q[1][0]+q[1][1])/2-q[0][0];
        a[2]=(q[0][0]+q[1][0]+q[1][1])/2-q[1][0];
        a[3]=(q[0][0]+q[1][0]+q[1][1])/2-q[1][1];
        m=3;
        for (i=1;i<q[0].size();i++)
            a[++m]=q[0][i]-a[1];
        for (i=2;i<q[1].size();i++)
            a[++m]=q[1][i]-a[1];
        printf("YES\n");
        for (i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return 0;
    }
    if (n<=3){
        printf("NO\n");
        return 0;
    }
    q[0].clear();q[1].clear();
    N=min(n,25);
    dfs1(1,0,0);mop[make_pair(0,0)]--;
    dfs2(N,0,0,0);
    if (!flag){
        printf("NO\n");
        return 0;
    }
    flag=false;
    dfs3(1,0,0);
    a[m=1]=0;
    for (i=0;i<q[0].size();i++){
        m++;a[m]=q[0][i]-a[m-1];
        m++;a[m]=q[1][i]-a[m-1];
    }
    m--;
    for (i=1;i<=n;i++)
        if (!vis[i])
            a[++m]=b[i]-a[1];
    printf("YES\n");
    for (i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
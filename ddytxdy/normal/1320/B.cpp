#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,m,a[N],ver[N],nxt[N],head[N],tot,d[N],q[N],l,r,k,ans1,ans2;
vector<int>v[N];
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++)
        scanf("%d%d",&x,&y),add(y,x),v[x].push_back(y);
    scanf("%d",&k);
    for(int i=1;i<=k;i++)scanf("%d",&a[i]);
    memset(d,0x3f,sizeof(d));q[l=r=1]=a[k];d[a[k]]=0;
    while(l<=r){
        int x=q[l++];
        for(int i=head[x],y;i;i=nxt[i])
            if(d[y=ver[i]]>d[x]+1)d[y]=d[x]+1,q[++r]=y;
    }
    // for(int i=1;i<=n;i++)printf("%d ",d[i]);
    for(int i=1;i<k;i++){
        if(d[a[i]]!=d[a[i+1]]+1)ans1++,ans2++;
        else{
            int num=0;
            for(int j=0;j<v[a[i]].size();j++)
                if(d[v[a[i]][j]]+1==d[a[i]])num++;
            ans2+=num!=1;
        }
    }
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
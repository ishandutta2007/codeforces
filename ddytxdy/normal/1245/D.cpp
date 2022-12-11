#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2010;
int n,x[N],y[N],m,k[N],f[N];LL ans;
vector<int>ans1;
vector<pair<int,int> >ans2;
struct node{int x,y;LL z;bool friend operator <(node a,node b){return a.z<b.z;}}a[N*N*2];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int dis(int i,int j){return abs(x[i]-x[j])+abs(y[i]-y[j]);}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++)scanf("%d%d",&x[i],&y[i]);
    for(int i=1,x;i<=n;i++)scanf("%d",&x),a[++m]=(node){0,i,x};
    for(int i=1;i<=n;i++)scanf("%d",&k[i]);
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)a[++m]=(node){i,j,1ll*dis(i,j)*(k[i]+k[j])};
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++){
        int x=a[i].x,y=a[i].y;
        int fx=find(x),fy=find(y);
        if(fx==fy)continue;
        f[fx]=fy;ans+=a[i].z;
        if(x>y)swap(x,y);
        if(!x)ans1.push_back(y);
        else ans2.push_back(make_pair(x,y));
    }
    cout<<ans<<endl;
    printf("%d\n",ans1.size());
    for(int i=0;i<ans1.size();i++)printf("%d ",ans1[i]);puts("");
    printf("%d\n",ans2.size());
    for(int i=0;i<ans2.size();i++)printf("%d %d\n",ans2[i].first,ans2[i].second);
    return 0;
}
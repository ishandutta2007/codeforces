#include<bits/stdc++.h>
using namespace std;
int a[200005],sum[200005],b[200005],f[200005];
vector<int>e[200005];
bool cmp(int x,int y){
    return sum[x]>sum[y];
}
int main(){
    int t,n,i,j,k,m;
    cin>>t;
    while(t--){
        cin>>n;m=0;
        for(i=1;i<=n;++i){
            scanf("%d",&a[i]);
            ++sum[a[i]];
            if(sum[a[i]]==1){
                b[++m]=a[i];
            }
            e[a[i]].push_back(i);
        }
        sort(b+1,b+1+m,cmp);
        //for(i=1;i<=m;++i)printf("%d %d\n",b[i],sum[b[i]]);
        for(i=1;i<=sum[b[1]];++i){
            for(j=1;e[b[j]].size()>=i;++j){
                if(e[b[j+1]].size()>=i)f[e[b[j]][i-1]]=e[b[j+1]][i-1];
                else{
                    f[e[b[j]][i-1]]=e[b[1]][i-1];
                }
            }
        }
        for(i=1;i<=n;++i)printf("%d ",a[f[i]]);puts("");
        for(i=1;i<=n;++i){
            sum[a[i]]=0;
            f[i]=0;
            b[i]=0;
            e[a[i]].clear();
        }
    }
    return 0;
}
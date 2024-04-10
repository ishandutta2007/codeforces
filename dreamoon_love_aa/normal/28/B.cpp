#include<stdio.h>
#include<vector>
using namespace std;
int a[110],d[110],k,r[110],rr[110];
bool used[110];
vector<int>Map[110];
void dfs(int x,int n){
    if(used[x])return;
    used[x]=1;
    r[x]=k;
    rr[a[x]]=k;
    int i;
    for(i=0;i<Map[x].size();i++)
        dfs(Map[x][i],n);
}
main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        scanf("%d",&d[i]);
        if(i>d[i]){
            Map[i].push_back(i-d[i]);
            Map[i-d[i]].push_back(i);
        }
        if(i+d[i]<=n){
            Map[i].push_back(i+d[i]);
            Map[i+d[i]].push_back(i);
        }
    }
    for(i=1;i<=n;i++){
        if(!used[i]){
            k++;
            dfs(i,n);
            for(j=1;j<=n;j++)
                if(r[j]!=rr[j])break;
            if(j<=n)break;
        }
    }
    if(i<=n)puts("NO");
    else puts("YES");
}
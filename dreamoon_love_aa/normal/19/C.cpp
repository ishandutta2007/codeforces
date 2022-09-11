#include<stdio.h>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>Map;
vector<int>d[100010],u[100010];
int a[100010];
main(){
    int n,m=0,i,j,k,now=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++){
        if(Map.count(a[i]))d[Map[a[i]]].push_back(i);
        else{
            Map[a[i]]=m++;
            d[m-1].push_back(i);
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<d[i].size();j++)
            for(k=j+1;k<d[i].size();k++)u[d[i][k]-d[i][j]].push_back(d[i][j]);
    }
    for(i=1;i<n;i++){
        sort(u[i].begin(),u[i].end());
        for(j=0;j<u[i].size();j=k){
            if(u[i][j]<now){
                k=j+1;
                continue;
            }
            for(k=j+1;k-j<i&&k<u[i].size()&&u[i][k]==u[i][k-1]+1;k++);
            if(k-j==i)now=u[i][j]+i;
        }
    }
    printf("%d\n",n-now);
    for(printf("%d",a[now++]);now<n;now++)
        printf(" %d",a[now]);
    puts("");
}
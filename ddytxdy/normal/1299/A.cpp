#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int n,a[N];bool vis[N];
vector<int>v[30];
int main(){
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<30;j++)
            if(a[i]>>j&1)v[j].push_back(i);
    }
    for(int j=29;~j;j--)
        if(v[j].size()==1)
            {printf("%d ",a[v[j][0]]);vis[v[j][0]]=1;break;}
    for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",a[i]);
}
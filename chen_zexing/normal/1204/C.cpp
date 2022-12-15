#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int dis[105][105];
char s[105][105];
vector <int> ans;
int a[1000005];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=i==j?0:999999;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(s[i][j]=='1')
                dis[i][j]=1;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    int m,t,p,now=0;
    cin>>m;
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        if(i==1){
            p=a[i];
            now=0;
            ans.push_back(p);
        }
        else{
            now++;
            if(dis[p][a[i]]<now){
                p=a[i-1];
                now=1;
                ans.push_back(p);
            }
        }
    }
    ans.push_back(a[m]);
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
    return 0;
}
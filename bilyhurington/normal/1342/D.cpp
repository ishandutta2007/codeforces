/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-04-26 23:42:42
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n,k,a[200010],c[200010],siz[200010];
vector<int> v[200010];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=k;i++) scanf("%d",&c[i]);
    sort(a+1,a+n+1);
    int now=1;
    for(int i=n;i>=1;i--){
        if(c[a[i]]!=c[a[i+1]]) now=1;
        if(v[now].size()==c[a[i]]) now++;
        v[now].push_back(a[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(v[i].size()) ans++;
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++){
        printf("%d ",v[i].size());
        for(int j=0;j<v[i].size();j++) printf("%d ",v[i][j]);
        printf("\n");
    }
    return 0;
}
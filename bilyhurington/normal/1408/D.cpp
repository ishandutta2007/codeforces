/*
 * @Author: BilyHurington
 * @Date: 2020-09-30 22:35:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-30 23:57:47
 */
#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
pair<int,int> p1[2010],p2[2010],P[2010*2010];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d %d",&p1[i].first,&p1[i].second);
    for(int i=1;i<=m;i++) scanf("%d %d",&p2[i].first,&p2[i].second);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(p2[j].first<p1[i].first||p2[j].second<p1[i].second) continue;
            P[++tot]=make_pair(p2[j].first-p1[i].first+1,p2[j].second-p1[i].second+1);
        }
    }
    sort(P+1,P+tot+1);int maxn=0,ans=2e9;
    for(int i=tot;i>=0;i--){
        ans=min(ans,maxn+P[i].first);
        maxn=max(maxn,P[i].second);
    }
    printf("%d",ans);
    return 0;
}
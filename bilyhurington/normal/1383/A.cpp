/*
 * @Author: BilyHurington
 * @Date: 2020-07-24 22:37:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-24 23:13:18
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[25][25];
char A[100010],B[100010];
vector<int> v[25];
void solve(){
    memset(cnt,0,sizeof(cnt));
    scanf("%d",&n);
    scanf("%s%s",A+1,B+1);
    for(int i=1;i<=n;i++){
        if(A[i]>B[i]){printf("-1\n");return;}
        if(A[i]!=B[i]){
            cnt[A[i]-'a'+1][B[i]-'a'+1]++;
        }
    }
    for(int i=1;i<=20;i++) v[i].clear();
    vector<pair<int,int> > vec;
    for(int i=1;i<=20;i++){
        for(int j=1;j<=20;j++) if(cnt[i][j]) v[j].push_back(i);
    }
    int ans=0;
    for(int i=20;i>=1;i--){
        if(v[i].size()<=1){ans+=v[i].size();continue;}
        sort(v[i].begin(),v[i].end());
        v[i].erase(unique(v[i].begin(),v[i].end()),v[i].end());
        for(int j=0;j<v[i].size()-1;j++){
            v[v[i][j+1]].push_back(v[i][j]);
        }
        ans++;
    } 
    printf("%d\n",ans);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
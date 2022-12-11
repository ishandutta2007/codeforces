#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;char s[N],t[N];
vector<int>ans;
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++)s[i]=s[i]=='W';
    memcpy(t,s,sizeof(s));
    for(int i=1;i<n;i++)
        if(t[i])ans.push_back(i),t[i+1]^=1;
    if(!t[n]){
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
        exit(0);
    }
    memcpy(t,s,sizeof(s));ans.clear();
    for(int i=1;i<n;i++)
        if(!t[i])ans.push_back(i),t[i+1]^=1;
    if(t[n]){
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);
        exit(0);
    }
    puts("-1");
    return 0;
}
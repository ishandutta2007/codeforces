#include<bits/stdc++.h>
using namespace std;
int a[200005];
vector<pair<int, int>>ans;
void work(){
    int n,i,s=0;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(i%2==0)a[i]=-a[i];
        s+=a[i];
    }
    if(s&1){
        puts("-1");
        return;
    }
    ans.clear();
    int j;
    for(i=1;i<=n;){
        if(a[i]==0){
            ans.emplace_back(i,i);
            ++i;
        }
        else{
            for(j=i+1;a[j]==0;++j);
            if(a[i]+a[j]==0){
                ans.emplace_back(i,j);
                i=j+1;
            }
            else{
                ans.emplace_back(i,i);
                ans.emplace_back(i+1,j);
                i=j+1;
            }
        }
    }
    printf("%d\n",ans.size());
    for(i=0;i<ans.size();++i){
        printf("%d %d\n",ans[i].first, ans[i].second);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        work();
    }
    return 0;
}
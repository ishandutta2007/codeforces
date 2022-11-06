#include<bits/stdc++.h>
using namespace std;
int a[200005];
vector<pair<int, int>>ans;
void work(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
        if(i%2==0)a[i]=-a[i];
    }
    if(n&1){
        puts("-1");
        return;
    }
    ans.clear();
    for(i=1;i<=n;i+=2){
        if(a[i]+a[i+1]==0){
            ans.emplace_back(i, i+1);
        }
        else{
            ans.emplace_back(i, i);
            ans.emplace_back(i+1, i+1);
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
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n,a[1000010],nxt[1000010];
bool vis[1000010];
void solve(){
    scanf("%d",&n);int t=1,t2;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),nxt[i]=i-a[i],vis[i]=0;
    while(!vis[t]) vis[t]=1,t=nxt[t];
    vector<int> Ans;
    Ans.push_back(t);t2=nxt[t];
    while(t2!=t) Ans.push_back(t2),t2=nxt[t2];
    printf("%d\n",(int)Ans.size());
    for(auto x:Ans) printf("%d ",x);
    puts("");
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--) solve();
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
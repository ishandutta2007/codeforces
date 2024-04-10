#include <bits/stdc++.h>
using namespace std;

bool used[5005];
int n,w,h;
int a[5005];
int b[5005];
int ans[5005];
int to[5005];
void dfs(int x){
    if (used[x]) return;
    used[x]=true;
    ans[x]=1;
    to[x]=-1;
    for (int i=1;i<=n;++i) {
        if (a[i]>a[x] && b[i]>b[x]) {
            dfs(i);
            if (ans[i]+1>ans[x]) {
                ans[x]=ans[i]+1;
                to[x]=i;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>w>>h;
    for (int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;++i)
        if (used[i]==false) dfs(i);
    int k=-1;
    for (int i=1;i<=n;++i)
    if (a[i]>w && b[i]>h) {
        if (k==-1 || ans[i]>ans[k]) k=i;
    }
    if (k==-1) {
        cout<<0;
        return 0;
    }
    vector<int> v;
    while (k!=-1) {
        v.push_back(k);
        k=to[k];
    }
    cout<<v.size()<<'\n';
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}
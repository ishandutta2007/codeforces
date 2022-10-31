#include <bits/stdc++.h>
using namespace std;
int n;
int a[3005];
int b[305][305];
vector<int> v;
vector<int> v2;
bool used[305];
void dfs(int x){
    used[x]=true;
    v.push_back(x);
    v2.push_back(a[x]);
    for (int j=1;j<=n;++j)
        if (b[x][j]==1 && used[j]==false) dfs(j);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i){
        for  (int j=1;j<=n;++j){
            char c;
            cin>>c;
            b[i][j]=c-'0';
        }
    }
    for (int i=1;i<=n;++i){
        if (used[i]==false){
            v.clear();
            v2.clear();
            dfs(i);
            sort(v.begin(),v.end());
            sort(v2.begin(),v2.end());
            for (int i=0;i<v.size();++i)
                a[v[i]]=v2[i];
        }
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}
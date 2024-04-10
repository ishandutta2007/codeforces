#include <bits/stdc++.h>
using namespace std;

int n,x,y;
vector<int> v[100005];
long long a[100005];
long long n1[100005];
long long n2[100005];

void dfs(int x,int p=-1){
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==p) continue;
        dfs(to,x);
        n1[x]=max(n1[x],n1[to]);
        n2[x]=max(n2[x],n2[to]);
    }
    a[x]=a[x]-n2[x]+n1[x];
    if (a[x]>0) n2[x]+=a[x];
    else n1[x]-=a[x];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    dfs(1);
    cout<<n1[1]+n2[1];
}
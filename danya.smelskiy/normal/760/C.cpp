#include <bits/stdc++.h>
using namespace std;

long long n,ans;
long long x,kol,last;
long long a[200001];
set<int> q;
bool used[200001];
inline void dfs(int x){
    used[x]=true;
    q.erase(x);
    ++kol;
    last=x;
    if (used[a[x]]==false) dfs(a[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        q.insert(i);
    }
    for (int i=1;i<=n;++i){
        cin>>x;
        if (x==1) ++ans;
    }
    ++ans;
    ans%=2;
    dfs(1);
    while (true){
        if (kol==n) break;
        int y=*q.begin();
        a[last]=y;
        dfs(y);
        ++ans;
    }
    if (a[last]!=1) ++ans;
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
bool used[5];
int ans[100005];


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x=0;
        for (int j=1;j<=3;++j) {
            cin>>a[j];
            x=max(x,ans[a[j]]);
            used[j]=false;
        }
        used[x]=true;
        for (int j=1;j<=3;++j)
            if (ans[a[j]]==0)
        for (int k=1;k<=3;++k) if (used[k]==false) {
            used[k]=true;
            ans[a[j]]=k;
            break;
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}
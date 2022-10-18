#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        a[u]++;
        a[v]++;
    }
    bool ok=1;
    for(int i=1;i<=n;i++){
        if(a[i]==2) ok=0;
    }
    cout<<(ok?"YES":"NO");
    return 0;
}
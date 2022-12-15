#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[200005],b[200005],id[200005];
int p1[200005],p2[200005];
vector <int> v[200005];
bool cmp(int a,int b){
    return v[a].size()>v[b].size();
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[i].clear(),id[i]=i;
        for(int i=1;i<=n;i++) v[a[i]].push_back(i);
        sort(id+1,id+n+1,cmp);
        for(int i=1,x=0;i<=n;i++){
            for(auto t:v[id[i]]) p1[++x]=t;
        }
        for(int i=2,x=0;i<=n+1;i++){
            for(auto t:v[id[i<=n?i:i-n]]) p2[++x]=t;
        }
        for(int i=1;i<=n;i++) b[p1[i]]=a[p2[i]];
        for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
    }
    return 0;
}
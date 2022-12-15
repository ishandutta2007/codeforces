#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],b[100005];
vector <int> v[2];
bool cmp(int x,int y){
    return b[x]>b[y];
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        v[0].clear(),v[1].clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),v[a[i]].push_back(i);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(v[0].begin(),v[0].end(),cmp);
        sort(v[1].begin(),v[1].end(),cmp);
        long long sum=0;
        for(int i=1;i<=n;i++) sum+=b[i];
        if(v[0].size()==v[1].size()){
            long long ans=0;
            int mn=INT_MAX;
            for(int i=1;i<=n;i++) ans+=b[i],mn=min(mn,b[i]);
            printf("%lld\n",sum+ans-mn);
        }
        else{
            if(v[0].size()<v[1].size()) swap(v[0],v[1]);
            long long ans=0;
            for(int i=0;i<v[1].size();i++) ans+=b[v[0][i]]+b[v[1][i]];
            printf("%lld\n",sum+ans);
        }
    }
    return 0;
}
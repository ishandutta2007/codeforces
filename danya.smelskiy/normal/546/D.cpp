#include <bits/stdc++.h>
using namespace std;
int n,x,y;
int m;
long long res[5000001];
int sz=1;
int q[600001];
long long  l[5000001];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int m=5000001;
    for (int i=2;i<=m;++i){
        if (l[i]==0) {
            l[i]=i;
            ++sz;
            q[sz]=i;
        }
        for (int j=1;j<=sz && q[j]<=i && i*q[j]<m;++j)
            l[i*q[j]]=q[j];
        res[i]=1+res[i/l[i]];
    }
    for (int i=1;i<=m;++i)
        res[i]+=res[i-1];
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        cout<<res[x]-res[y]<<'\n';
    }
}
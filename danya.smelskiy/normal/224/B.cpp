#include <bits/stdc++.h>
using namespace std;
int n,k,a[100001];
map<int,int> kol;
int l,now;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ++kol[a[i]];
        if (kol[a[i]]==1) ++now;
    }
    if (now<k){
        cout<<"-1 -1";
        return 0;
    }
    int r=0;
    for (int i=n;i>0;i--){
        int x=a[i];
        r=i;
        if (kol[x]==1 && now==k) break;
        --kol[x];
        if (kol[x]==0) --now;
    }
    for (int i=1;i<=n;++i){
        if (i>r) break;
        int x=a[i];
        l=i;
        if (kol[x]==1 && now==k) break;
        --kol[x];
        if (kol[x]==0) --now;
    }
    cout<<l<<" "<<r;
}
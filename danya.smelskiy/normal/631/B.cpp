#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int clr[100005];
int d1[5005];
int d2[5005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=k;++i) {
        int tp;
        int x;
        cin>>tp>>x>>clr[i];
        if (tp==1) d1[x]=i;
        else d2[x]=i;
    }
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=m;++j) {
            cout<<clr[max(d1[i],d2[j])]<<" ";
        }
        cout<<'\n';
    }

}
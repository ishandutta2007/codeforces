#include <bits/stdc++.h>
using namespace std;
int n,x,m,y;
int a[100001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        a[i]=a[i-1]+x;
    }
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>y;
        int l=1,r=n+1;
        while (l<r-1){
            int mid=(l+r)/2;
            if (a[mid]>y) r=mid;
            else l=mid;
        }
        if (a[l]>=y) cout<<l<<'\n';
        else cout<<r<<'\n';
    }
}
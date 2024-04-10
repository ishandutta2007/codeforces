#include <bits/stdc++.h>
using namespace std;

int n,m,a[100001],pos,ans,x;
int main(){
    cin>>n>>m;
    swap(n,m);
    for (int i=1;i<=n;++i){
            ans=-1;
        for (int j=1;j<=m;++j){
            cin>>x;
            if (x>ans){
                ans=x;
                pos=j;
            }
        }
        ++a[pos];
    }
    ans=-1;
    for (int i=1;i<=m;++i){
        if (a[i]>ans){
            ans=a[i];
            pos=i;
        }
    }
    cout<<pos;
}
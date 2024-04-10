#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100001];
int kol,x;
int ans;
int r;
int main(){
    cin>>n>>m>>r;
    for (int i=1;i<=m+1;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i){
        x=a[i]^a[m+1];
        kol=0;
        while (x>0){
            if (x%2==1) ++kol;
            x/=2;
        }
        if (kol<=r)++ans;
    }
    cout<<ans;
}
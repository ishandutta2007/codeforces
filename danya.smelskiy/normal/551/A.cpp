#include <bits/stdc++.h>
using namespace std;
int n;
int a[2001],b[2001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
    }
    for (int i=1;i<=n;++i){
        b[i]++;
        for (int j=1;j<=n;++j){
            if (a[j]>a[i]) b[i]++;
        }
    }
    for (int i=1;i<=n;++i)
        cout<<b[i]<<" ";
}
#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        while (a[i]%3==0) a[i]/=3;
        while (a[i]%2==0) a[i]/=2;
    }
    for (int i=1;i<=n;++i)
    if (a[i]!=a[1]) {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
}
#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,a[100001];
int main(){
    cin>>n;
    cin>>m;
    for (int i=1;i<n;++i)
        cin>>a[i];
    while (true){
        sort(a+1,a+n+1);
        if (a[n]<m) break;
        --a[n];
        ++ans;
        ++m;
    }
    cout<<ans;
}
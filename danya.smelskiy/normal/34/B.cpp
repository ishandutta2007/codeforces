#include <bits/stdc++.h>
using namespace std;
long long n,m,now,ans;
long long a[100001];
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for (int i=1;i<=n;++i){
        if (a[i]>=0 || now==m) break;
        now++;
        ans+=abs(a[i]);
    }
    cout<<ans;
}
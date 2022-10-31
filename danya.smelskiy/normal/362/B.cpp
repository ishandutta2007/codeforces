#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000001];

int main(){
    cin>>n>>m;
    for (int i=1;i<=m;++i)
        cin>>a[i];
    sort(a+1,a+m+1);
    bool t=false;
    for (int i=3;i<=m;++i)
        if (a[i]==a[i-1]+1 && a[i]==a[i-2]+2){
            t=true;
            break;
        }
    if (t==true || a[1]==1 || a[m]==n) cout<<"NO";
    else cout<<"YES";
}
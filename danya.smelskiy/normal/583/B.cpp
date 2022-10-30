#include <bits/stdc++.h>
using namespace std;
int n;
const long long inf=10e9;
int a[100001];
int now,ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    while (true){
        for (int i=1;i<=n;++i){
            if (a[i]<=now) { now++; a[i]=inf;}
        }
        if (now==n) break;
        ++ans;
        for (int i=n;i>0;--i){
            if (a[i]<=now) { now++; a[i]=inf;}
        }
        if (now==n) break;
        ++ans;
    }
    cout<<ans;
}
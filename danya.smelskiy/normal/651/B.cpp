#include <bits/stdc++.h>
using namespace std;
long long n,ans,kol,now,last;
long long a[10001];
bool used[10001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    while (kol<n){
        last=0;
        now=0;
        for (int j=1;j<=n;++j)
        if (used[j]==false && a[j]>last){
            last=a[j];
            used[j]=true;
            ++kol;
            ++now;
        }
        ans+=now-1;
    }
    cout<<ans;
}
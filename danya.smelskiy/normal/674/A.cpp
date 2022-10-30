#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005];
int kol[5005];
int ans[5005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
    }
    for (int i=1;i<=n;++i) {
        int mx1=0;
        int mx2=0;
        memset(kol,0,sizeof(kol));
        for (int j=i;j<=n;++j) {
            ++kol[a[j]];
            if (kol[a[j]]>mx1) {
                mx1=kol[a[j]];
                mx2=a[j];
            } else if (kol[a[j]]==mx1 && a[j]<mx2) {
                mx2=a[j];
            }
            ++ans[mx2];
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}
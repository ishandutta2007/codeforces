#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int a[100005];
int b[100005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    if (n>m) {
        cout<<"YES";
        return 0;
    }
    for (int i=1;i<=n;++i)
        if (a[i]>b[m-n+i]) {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
}
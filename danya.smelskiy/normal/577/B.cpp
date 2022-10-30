#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1000001];
bool dp1[5001];
bool dp2[5001];

int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>a[i]; a[i]%=m;
    }
    for (int i=1;i<=n;++i){
        dp2[a[i]]=true;
        for (int j=1;j<=m;++j)
            if (dp1[j]) dp2[(j+a[i])%m]=true;
        if (dp2[0]) {
            cout<<"YES";
            return 0;
        }
        for (int j=1;j<=m;++j)
            if (dp2[j]) dp1[j]=true;
    }
    cout<<"NO";
}
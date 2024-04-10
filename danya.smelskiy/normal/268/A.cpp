#include <bits/stdc++.h>
using namespace std;
int n;
int a[31],b[31];
int ans;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i]>>b[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            if (b[i]==a[j]) ++ans;
        }
    }
    cout<<ans;
}
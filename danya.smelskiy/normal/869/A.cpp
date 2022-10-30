#include <bits/stdc++.h>
using namespace std;

int n;
int a[5005],b[5005];
bool used[5000005];
int ans;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        used[a[i]]=true;
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
        used[b[i]]=true;
    }

    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
        if (used[(a[i]^b[j])]) ++ans;
    if (ans%2==0) cout<<"Karen";
    else cout<<"Koyomi";
}
#include <bits/stdc++.h>
using namespace std;
int n,ans,a[1001];
bool used[1001];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ans+=a[i];
    }
    ans/=(n/2);
    for (int i=1;i<n;++i){
        if (used[i]==false){
                used[i]=true;
            for (int j=i+1;j<=n;++j){
                if (a[j]==ans-a[i] && used[j]==false){
                    used[j]=true;
                    cout<<i<<" "<<j<<'\n';
                    break;
                }
            }
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn];
int n,k;
int main(){
    cin>>n>>k;
    int ans = 200;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (k%a[i]==0){
            ans = min(ans,k/a[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n;
bool a[400005];
int cnt,ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[n+i]=a[i];
    }
    for(int i=1;i<=n*2;i++){
        if(a[i])cnt++;
        else cnt=0;
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
    
    return 0;
}
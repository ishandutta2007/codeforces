#include<bits/stdc++.h>
using namespace std;

int n,k;
char s[5005],t[5005],ans[5005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++)t[j]=s[j%i];
        if(memcmp(t,ans,k)<0||i==1)memcpy(ans,t,k);
    }
    cout<<ans;

    return 0;
}
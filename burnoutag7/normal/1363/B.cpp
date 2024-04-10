#include<bits/stdc++.h>
using namespace std;

int t;
char s[1005];
int pre[1005],suf[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>s+1;
        int n=strlen(s+1);
        pre[0]=suf[n+1]=0;
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+s[i]-'0';
        }
        for(int i=n;i>=1;i--){
            suf[i]=suf[i+1]+s[i]-'0';
        }
        int ans=1e9;
        for(int i=0;i<=n;i++){
            ans=min(ans,min(pre[i]+(n-i-suf[i+1]),(i-pre[i])+suf[i+1]));
        }
        cout<<ans<<endl;
    }

    return 0;
}
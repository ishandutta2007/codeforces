#include<bits/stdc++.h>
using namespace std;

int t,n,ans,cnt;
char s[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        cin>>s+1;
        ans=0;
        cnt=-1e9;
        for(int i=1;i<=n;i++){
            if(s[i]=='A'){
                ans=max(ans,cnt);
                cnt=0;
            }else{
                cnt++;
            }
        }
        ans=max(ans,cnt);
        cout<<ans<<endl;
    }

    return 0;
}
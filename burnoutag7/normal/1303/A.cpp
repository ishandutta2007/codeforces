#include<bits/stdc++.h>
using namespace std;

int T,n;
char s[105];
int tot,pre,suf;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>s+1;
        n=strlen(s+1);
        tot=pre=suf=0;
        for(int i=1;i<=n&&s[i]!='1';i++)pre++;
        for(int i=n;i>0&&s[i]!='1';i--)suf++;
        for(int i=1;i<=n;i++)tot+=s[i]=='0';
        cout<<max(tot-pre-suf,0)<<endl;
    }

    return 0;
}
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50,inf=1e9;
char s[N];int n,cnt[26];LL f[26][26],ans;
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++)f[j][s[i]-'a']+=cnt[j];
        cnt[s[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<26;j++)ans=max(ans,f[i][j]);
        ans=max(ans,1ll*cnt[i]);
    }
    cout<<ans;
    return 0;
}
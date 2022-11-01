#include<bits/stdc++.h>
using namespace std;

int n,sa[1<<18|5],rk[1<<18|5],cnt[1<<18|5],id[1<<18|5],nrk[1<<18|5];
char s[1<<18|5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i=0;i<1<<n;i++)cnt[s[i]-'a']++;
    for(int i=1;i<26;i++)cnt[i]+=cnt[i-1];
    for(int i=(1<<n)-1;i>=0;i--){
        sa[--cnt[s[i]-'a']]=i;
        rk[i]=s[i]-'a';
    }
    for(int x=0;x<n;x++){
        for(int i=0;i<1<<n;i++){
            id[i]=sa[i]^1<<x;
        }
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<1<<n;i++)cnt[rk[i]]++;
        for(int i=1;i<max(26,1<<n);i++)cnt[i]+=cnt[i-1];
        for(int i=(1<<n)-1;i>=0;i--){
            sa[--cnt[rk[id[i]]]]=id[i];
        }
        int cur=0;
        for(int i=0;i<1<<n;i++){
            cur+=i&&(rk[sa[i]]!=rk[sa[i-1]]||rk[sa[i]^1<<x]!=rk[sa[i-1]^1<<x]);
            nrk[sa[i]]=cur;
        }
        memcpy(rk,nrk,4<<n);
    }
    for(int i=0;i<1<<n;i++)cout<<s[i^sa[0]];

    return 0;
}
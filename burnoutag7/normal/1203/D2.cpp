#include<bits/stdc++.h>
using namespace std;

char s[200005];
char t[200005];
int slen,tlen;
int pre[200005];
int suf[200005];
int ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    slen=strlen(s+1);
    cin>>t+1;
    tlen=strlen(t+1);
    for(int i=1;i<=slen;i++){
        pre[i]=pre[i-1];
        if(s[i]==t[pre[i]+1]){
            pre[i]++;
        }
    }
    for(int i=slen;i>=1;i--){
        suf[i]=suf[i+1];
        if(s[i]==t[tlen-suf[i]]){
            suf[i]++;
        }
    }
    int l=0,r=1;
    while(l<=slen&&r<=slen+1){
        while(r<=slen+1&&suf[r]+pre[l]>=tlen)r++;
        r--;
        //cout<<r-l-1<<endl;
        ans=max(ans,r-l-1);
        l++;
    }
    cout<<ans<<endl;

    return 0;
}
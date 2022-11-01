#include<bits/stdc++.h>
using namespace std;

int n;
char s[200005],p[200005];

void mian(){
    cin>>s+1;
    n=strlen(s+1);
    long long ans=0;
    int st=0;
    while(s[st+1]=='?'&&st<n)st++;
    if(st==n){
        cout<<(long long)n*(n+1)/2<<'\n';
        return;
    }
    p[st]=s[st];
    for(int i=st;i>=1;i--)p[i]=p[i+1]^1;
    for(int i=st+1;i<=n;i++){
        p[i]=s[i]=='?'?p[i-1]^1:s[i];
    }
    for(int l=1,r=0,cnt=0;++r<=n;){
        if(s[r]!='?'){
            cnt++;
            if(p[r]==p[r-1]){
                while(cnt>1){
                    cnt-=s[l]!='?';
                    l++;
                }
            }
        }
        ans+=r-l+1;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,f[1<<20];
char s[1000005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        int c=0;
        for(int j=i;j<=n;j++){
            if(c>>s[j]-'a'&1)break;
            c|=1<<s[j]-'a';
            f[c]=__builtin_popcount(c);
        }
    }
    for(int c=1;c<1<<20;c++){
        for(int i=0;i<20;i++){
            if(c>>i&1)f[c]=max(f[c],f[c^1<<i]);
        }
    }
    int ans=0;
    for(int c=1;c<1<<20;c++){
        ans=max(ans,f[c]+f[c^(1<<20)-1]);
    }
    cout<<ans;

    return 0;
}
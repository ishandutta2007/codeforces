#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[200005],t[200005];
int pre[200005],suf[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s+1>>t+1;
    for(int i=1;i<=m;i++){
        int j;
        for(j=pre[i-1]+1;s[j]!=t[i];j++);
        pre[i]=j;
    }
    suf[m+1]=n+1;
    for(int i=m;i>=1;i--){
        int j;
        for(j=suf[i+1]-1;s[j]!=t[i];j--);
        suf[i]=j;
    }
    int ans=0;
    for(int i=1;i<m;i++){
        ans=max(ans,suf[i+1]-pre[i]);
    }
    cout<<ans;

    return 0;
}
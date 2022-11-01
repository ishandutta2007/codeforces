#include<bits/stdc++.h>
using namespace std;

char s[200005],t[100005];
int n,m,prv[200005],cur[200005],nxt[200005],trans[200005][26];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1;
    n=strlen(s+1);
    cin>>t+1;
    m=strlen(t+1);
    {
        int k=0;
        for(int i=2;i<=m;i++){
            while(k&&t[k+1]!=t[i])k=nxt[k];
            nxt[i]=k+=t[k+1]==t[i];
        }
        for(int i=0;i<=m;i++){
            for(char c='a';c<='z';c++){
                trans[i][c-'a']=t[i+1]==c?i+1:trans[nxt[i]][c-'a'];
            }
        }
    }
    memset(cur,0xc0,m+1<<2);
    cur[0]=0;
    for(int i=1;i<=n;i++){
        memcpy(prv,cur,m+1<<2);
        memset(cur,0xc0,m+1<<2);
        for(int c=0;c<26;c++)if(s[i]=='?'||s[i]==c+'a'){
            for(int j=0;j<=m;j++){
                cur[trans[j][c]]=max(cur[trans[j][c]],prv[j]+(trans[j][c]==m));
            }
        }
    }
    cout<<*max_element(cur,cur+m+1);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
char s[N],t[N];int n,m,a[N],b[N],pre[N][26],p[N],nxt[N][26];
int main(){
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1),m=strlen(t+1);
    for(int i=1,j=0;i<=n;i++){
        if(j<m&&s[i]==t[j+1])j++;
        a[i]=j;
    }
    for(int i=n,j=m+1;i;i--){
        if(j>1&&s[i]==t[j-1])j--;
        b[i]=j;
    }b[n+1]=m+1;
    for(int i=1;i<=m;i++){
        p[t[i]-'a']=i;
        for(int j=0;j<26;j++)pre[i][j]=p[j];
    }
    for(int i=0;i<26;i++)nxt[m+1][i]=p[i]=m+1;
    for(int i=m;i;i--){
        p[t[i]-'a']=i;
        for(int j=0;j<26;j++)nxt[i][j]=p[j];
    }
    for(int i=1;i<=n;i++){
        int x=t[a[i]]==s[i]?a[i]:pre[a[i-1]][s[i]-'a'];
        int y=t[b[i]]==s[i]?b[i]:nxt[b[i+1]][s[i]-'a'];
        if(x<y)puts("NO"),exit(0);
    }
    puts("YES");
    return 0;
}
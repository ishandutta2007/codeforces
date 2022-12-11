#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T,p[26],n,m,nxt[N][26],ans;char s[N],t[N];bool fl;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s%s",s+1,t+1);n=strlen(s+1),m=strlen(t+1);
        fill(p,p+26,n+1);ans=fl=0;
        for(int i=n;i;p[s[i]-'a']=i,i--)
            for(int j=0;j<26;j++)nxt[i][j]=p[j];
        for(int i=0;i<26;i++)nxt[0][i]=p[i];
        for(int i=1,q=n,c;i<=m;i++){
            if(nxt[0][c=t[i]-'a']>n){fl=1;break;}
            if(nxt[q][c]<=n)q=nxt[q][c];
            else ans++,q=nxt[0][c];
        }
        printf("%d\n",fl?-1:ans);
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char a[1000005],b[1000005];
int kmp[1000005],nxt[1000005][26],f[20000005];
int n,m;
inline int ask(int i,int j){
    return i*m+j;
}
inline int dfs(int i,int j){
    if (f[ask(i,j)]!=-1)return f[ask(i,j)];
    if (i==n+1)return 0;
    int s=0;
    if (a[i]!='?'){
        int nj=nxt[j][a[i]-'a'];
        if (nj==m)s++,nj=kmp[nj];
        s+=dfs(i+1,nj);
    }
    else{
        register int nj;
        for (register int k=0;k<26;k++){
            nj=nxt[j][k];
            if (nj==m)s=max(s,1+dfs(i+1,kmp[nj]));
            else s=max(s,dfs(i+1,nj));
        }
    }
    return f[ask(i,j)]=s;
}
int main(){
    scanf("%s%s",a+1,b+1);
    n=strlen(a+1),m=strlen(b+1);
    int j=0;
    for (int i=2;i<=m;i++){
        while(j&&b[j+1]!=b[i])j=kmp[j];
        if (b[j+1]==b[i])j++;
        kmp[i]=j;
    }
    for (int i=0;i<=m;i++){
        for (int j=0;j<26;j++){
            if ((b[i+1]-'a')==j)nxt[i][j]=i+1;
            else nxt[i][j]=nxt[kmp[i]][j];
        }
    }
    memset(f,-1,sizeof(f));
    cout<<dfs(1,0)<<endl;
    //ASASASASASASAS
}
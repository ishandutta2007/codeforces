#include<bits/stdc++.h>
using namespace std;

void calcNext(char *s,int *nxt,int len){
    nxt[0]=-1;
    int k=-1;
    for(int i=1;i<len;i++){
        while(k!=-1&&s[k+1]!=s[i])k=nxt[k];
        if(s[k+1]==s[i])k++;
        nxt[i]=k;
    }
}

int kmp(char *s,int sl,char *p,int pl,int *nxt){
    int k=-1;
    for(int i=0;i<sl;i++){
        while(k!=-1&&p[k+1]!=s[i]&&s[i])k=nxt[k];
        if(p[k+1]==s[i]||!s[i])k++;
        if(k==pl-1)return i-pl+1;
    }
    return -1;
}

char s[3][100005];
char res[300005];
int len[3],r[3],st[3],ans=0x3f3f3f3f;
int nxt[3][100005];

int main(){

    for(int i=0;i<3;i++){
        scanf("%s",s[i]);
        len[i]=strlen(s[i]);
        calcNext(s[i],nxt[i],len[i]);
    }
    iota(r,r+3,0);
    do{
        memset(res,0,sizeof(res));
        int tmp=0;
        for(int i=0;i<3;i++){
            st[i]=kmp(res,300000,s[r[i]],len[r[i]],nxt[r[i]]);
            memcpy(res+st[i],s[r[i]],len[r[i]]);
            tmp=max(tmp,st[i]+len[r[i]]);
        }
        ans=min(ans,tmp);
    }while(next_permutation(r,r+3));
    cout<<ans<<endl;

    return 0;
}
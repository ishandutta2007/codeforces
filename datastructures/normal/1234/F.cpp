#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[1000005];
int n,book[2000005],f[2000005],ans;
int c[21][2000005],tot[25];
inline int lowbit(register int x){
    return x&(-x);
}
inline void out(int x){
    if (x==0)return;
    out(x/2);
    putchar(x%2+'0');
    return;
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    int inf=(1<<20);
    for (register int i=1;i<=n;i++){
        int now=0;
        for (register int j=1;j<=20;j++){
            if ((now&(1<<(s[i+j-1]-'a')))!=0)break;
            now|=(1<<(s[i+j-1]-'a'));
            book[now]=1;
        }
    }
    for (register int i=0;i<=inf;i++){
        register int len=0,ii=i;
        while(ii)len++,ii-=lowbit(ii);
        c[len][++tot[len]]=i;
    }
    for (register int ii=0;ii<=20;ii++){
        for (register int jj=1;jj<=tot[ii];jj++){
            register int i=c[ii][jj];
            for (register int j=0;j<=20;j++){
                if ((i&(1<<j))!=0)f[i]=max(f[i],f[i-(1<<j)]);
            }
            if (book[i]==1)f[i]=max(f[i],ii);       
        }
    }
    
    for (register int ii=0;ii<=20;ii++){
        for (register int jj=1;jj<=tot[ii];jj++){
            register int i=c[ii][jj],j=0;
            if (book[i]==0)continue;
            for (register int k=0;k<20;k++)
                if ((i&(1<<k))==0)j+=(1<<k);
            ans=max(ans,ii+f[j]);
        }
    }
    cout<<ans<<endl;
}
/*
 * @Author: BilyHurington
 * @Date: 2020-06-08 13:09:27
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-06-08 13:42:08
 */ 
#include<bits/stdc++.h>
using namespace std;
int n;char s1[1000010],s[1000010];
const int mod=1e9+7;
namespace Palindrome_Automation{
    int ch[1000010][26],fail[1000010],len[1000010],delta[1000010],jump[1000010],tot,last_node;
    int f[1000010],jump_sum[1000010];
    void init(){
        jump[0]=fail[0]=1;
        len[1]=-1;
        tot=1;
    }
    void insert(int x){
        int p=last_node;
        while(s[x-len[p]-1]!=s[x]) p=fail[p];
        if(!ch[p][s[x]-'a']){
            int q=fail[p];
            while(s[x-len[q]-1]!=s[x]) q=fail[q];
            len[++tot]=len[p]+2;
            fail[tot]=ch[q][s[x]-'a'];
            ch[p][s[x]-'a']=tot;
            delta[tot]=len[tot]-len[fail[tot]];
            if(delta[fail[tot]]==delta[tot]) jump[tot]=jump[fail[tot]];
            else jump[tot]=fail[tot];
        }
        last_node=ch[p][s[x]-'a'];
    }
    int solve(){
        init();f[0]=1;
        for(int i=1;i<=n;i++){
            insert(i);
            for(int tmp=last_node;tmp>1;tmp=jump[tmp]){
                jump_sum[tmp]=f[i-len[jump[tmp]]-delta[tmp]];
                if(delta[fail[tmp]]==delta[tmp]) jump_sum[tmp]=(jump_sum[tmp]+jump_sum[fail[tmp]])%mod; 
                f[i]=(f[i]+jump_sum[tmp])%mod;
            }
            if(i&1) f[i]=0;
        }
        return f[n];
    }
}
int main(){
    scanf("%s",s1+1);
    n=strlen(s1+1);
    if(n&1){printf("0");return 0;}
    for(int i=1;i<=n/2;i++) s[i*2-1]=s1[i],s[i*2]=s1[n+1-i];
    printf("%d",Palindrome_Automation::solve());
    return 0;
}
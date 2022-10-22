/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-20 00:06:08
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n,m;
char s[1000010],s2[1000010],s3[1000010];
const long long tmp=18593,mod=1956578931;
struct String_Hash{
    long long Ha[1000010],jc[1000010];
    void pre(char *s,int len){
        for(int i=1;i<=len;i++) Ha[i]=(Ha[i-1]*tmp%mod+s[i])%mod;
        jc[0]=1;
        for(int i=1;i<=len;i++) jc[i]=jc[i-1]*tmp%mod;
    }
    unsigned long long get(int l,int r){
        return (Ha[r]-Ha[l-1]*jc[r-l+1]%mod+mod)%mod;
    }
}Hash,Hash_inv;
bool check(int l,int r){return (Hash.get(l,r)==Hash_inv.get(m+1-r,m+1-l));}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int l=1,r=n;
        while(l+1<r&&s[l]==s[r]) l++,r--;
        m=0;
        for(int i=l;i<=r;i++) s2[++m]=s[i];
        for(int i=1;i<=m;i++) s3[m+1-i]=s2[i];
        Hash.pre(s2,m);
        Hash_inv.pre(s3,m);
        int ans=1,ansl=1,ansr=1;
        for(int i=1;i<=m;i++){
            if(check(1,i)){
                if(i>ans) ans=i,ansl=1,ansr=i;
            }
            if(check(i,m)){
                if((m-i+1)>ans) ans=m-i+1,ansl=i,ansr=m;
            }
        }
        for(int i=1;i<l;i++) printf("%c",s[i]);
        for(int i=ansl;i<=ansr;i++) printf("%c",s2[i]);
        for(int i=r+1;i<=n;i++) printf("%c",s[i]);
        printf("\n");
    }
}
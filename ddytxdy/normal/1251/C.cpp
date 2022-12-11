#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int t,n,l1,l2;char s[N],s1[N],s2[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);n=strlen(s+1);l1=l2=0;
        for(int i=1;i<=n;i++)
            if(s[i]&1)s1[++l1]=s[i];
            else s2[++l2]=s[i];
        s1[l1+1]=s2[l2+1]='9'+1;
        for(int i=1,j=1;i<=l1||j<=l2;){
            if(s1[i]<s2[j])s[i+j-1]=s1[i++];
            else s[i+j-1]=s2[j++];
        }
        printf("%s\n",s+1);
    }
}
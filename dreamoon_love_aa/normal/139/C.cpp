#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int fal[3],len[4],k;
char s[4][10005];
bool vow(char c){
    return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
bool test(char s1[],char s2[]){
    int l1=strlen(s1),l2=strlen(s2),cnt=0,i;
    for(i=1;i<=l1&&i<=l2;i++){
        if(s1[l1-i]!=s2[l2-i])return 0;
        if(vow(s1[l1-i]))cnt++;
        if(cnt==k)return 1;
    }
    return 0;
}
void Go(){
    int i;
    for(i=0;i<4;i++)scanf("%s",s[i]);
    if(!test(s[0],s[1]))fal[0]=1;
    if(!test(s[0],s[2]))fal[1]=1;
    if(!test(s[0],s[3]))fal[2]=1;
    if(!test(s[1],s[2]))fal[2]=1;
    if(!test(s[1],s[3]))fal[1]=1;
    if(!test(s[2],s[3]))fal[0]=1;
}
int main(){
    int i,j,n;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        Go();
    }
    if(!fal[0]&&!fal[1]&&!fal[2])puts("aaaa");
    else if(fal[0]&&fal[1]&&fal[2])puts("NO");
    else if(!fal[0])puts("aabb");
    else if(!fal[1])puts("abab");
    else if(!fal[2])puts("abba");
    return 0;
}
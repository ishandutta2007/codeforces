#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[1000000];
char find(char c1,char c2){
    char i;
    for(i='A';i==c1||i==c2;i++);
    return i;
}
int main(){
    int i,j,k,n;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    if(k==2){
        int cnt=0;
        for(i=0;i<n;i++){
            if(i%2==s[i]-'A')cnt++;
        }
        if(cnt>=n-cnt){
            printf("%d\n",n-cnt);
            for(i=0;i<n;i++)printf("%c",'A'+i%2);
        }
        else{
            printf("%d\n",cnt);
            for(i=0;i<n;i++)printf("%c",'A'+1-i%2);
        }
        puts("");
    }
    else{
        int cnt=0;
        for(i=0;i<n;i+=j){
            for(j=0;i+j<n&&s[i]==s[i+j];j++);
            cnt+=j/2;
        }
        printf("%d\n",cnt);
        char last='A';
        for(i=0;i<n;i+=j){
            for(j=0;i+j<n&&s[i]==s[i+j];j++);
            if(j%2==1){
                for(k=0;k<j;k++){
                    if(k&1)printf("%c",find(s[i],'A'));
                    else printf("%c",s[i]);
                }
                last=s[i];
            }
            else{
                for(k=0;k<j;k++){
                    if(k&1)printf("%c",s[i]);
                    else printf("%c",find(s[i],last));
                }
                last=s[i];
            }
        }
        puts("");
    }
    return 0;
}
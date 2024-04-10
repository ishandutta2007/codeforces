#include<stdio.h>
#include<string.h>
int a[26];
int main(){
    char c[1005];
    scanf("%s",c);
    int n=strlen(c),k=0;
    for(int i=0;i<n;i++){
        a[c[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        if(a[i]%2==1)k++;
    if((k==0)||((n%2)==1))printf("First");
    else printf("Second");
}
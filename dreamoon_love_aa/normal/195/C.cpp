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
#include<sstream>
#define pb push_back
using namespace std;
char s[55];
int n,m,lv[100010];
int main(){
    int i,j,k,n,len;
    char ee[100]="";
    scanf("%d",&n);
    gets(s);
    for(i=k=0;i<n;i++){
        gets(s);
        for(j=0;s[j]==' ';j++);
        if(strncmp(s+j,"try",3)==0)k++;
        else if(strncmp(s+j,"catch",5)==0){
            if(lv[k]==1){
                lv[k]=0;
                for(;s[j]!='(';j++);
                j++;
                while(s[j]==' ')j++;
                int r=0;
                for(r=0;r<len;r++)
                    if(ee[r]!=s[j+r])break;
                if(r==len&&(s[j+r]==','||s[j+r]==' ')){
                    j+=r;
                    while(s[j]!='\"')j++;
                    j++;
                    for(;s[j]!='\"';j++)printf("%c",s[j]);
                    puts("");
                    return 0;
                }
            }
            k--;
        }
        else if(strncmp(s+j,"throw",5)==0){
            while(s[j]!='(')j++;
            j++;
            int kk;
            for(kk=j;s[kk]!=')';kk++);
            s[kk]=' ';
            sscanf(s+j,"%s",ee);
            len=strlen(ee);
            for(j=1;j<=k;j++)lv[j]=1;
        }
    }
    printf("Unhandled Exception");
    return 0;
}
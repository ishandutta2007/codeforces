#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
using namespace std;
map<string,int>H;
main(){
    int n,ma=0,i;
    char s[99],an[99];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        if(H.count(s)==0){
            H[s]=1;
            if(H[s]>ma){
                ma=H[s];
                strcpy(an,s);
            }
        }
        else{
            H[s]++;
            if(H[s]>ma){
                ma=H[s];
                strcpy(an,s);
            }
        }
    }
    puts(an);
}
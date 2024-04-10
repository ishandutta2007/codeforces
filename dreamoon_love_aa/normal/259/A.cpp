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
int main(){
    int i,j,k,n,cnt=0,cnt2=0;
    char s[11];
    for(i=0;i<8;i++){
        scanf("%s",s);
        cnt2=0;
        for(j=0;j<8;j++){
            if(s[j]=='W'){
                cnt2++;
            }
            if(j&&s[j]==s[j-1])break;
        }
        if(cnt2!=4||j<8){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
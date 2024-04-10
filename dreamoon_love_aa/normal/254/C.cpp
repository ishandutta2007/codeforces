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
char s[2][100010];
int d[2][26],cnt[2][26];
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n;
    scanf("%s%s",s[0],s[1]);
    for(i=0;i<2;i++)
        for(j=0;s[i][j];j++){d[i][s[i][j]-'A']++;cnt[i][s[i][j]-'A']++;}
    int an=0;
    for(i=0;i<26;i++)an+=abs(d[0][i]-d[1][i]);
    printf("%d\n",an>>1);
    for(i=0;s[1][i];i++){
        cnt[0][s[0][i]-'A']--;
        if(d[0][s[0][i]-'A']>d[1][s[0][i]-'A']){
            for(j=0;j<s[0][i]-'A';j++){
                if(d[0][j]<d[1][j]){
                    d[0][j]++;
                    d[0][s[0][i]-'A']--;
                    s[0][i]='A'+j;
                    break;
                }
            }
            if(j<s[0][i]-'A')continue;
            if(d[0][s[0][i]-'A']>d[1][s[0][i]-'A']+cnt[0][s[0][i]-'A']){
                for(j++;j<26;j++){
                    if(d[0][j]<d[1][j]){
                        d[0][j]++;
                        d[0][s[0][i]-'A']--;
                        s[0][i]='A'+j;
                        break;
                    }
                }
            }
        }
    }
    puts(s[0]);
    return 0;
}
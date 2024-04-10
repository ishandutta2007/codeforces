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
#define SIZE 110000
using namespace std;
int m,d[10],now,len;
char s[SIZE],an1[SIZE],an2[SIZE];
void test(int x,int y){
    int d1[10],d2[10],i,j;
    for(i=0;i<10;i++)d1[i]=d2[i]=d[i];
    d1[x]--;
    d2[y]--;
    if(d1[x]<0||d2[y]<0)return;
    int an=1;
    for(i=0;i<=9;i++)an+=min(d1[i],d2[9-i]);
    int tmp;
    an+=tmp=max(0,min(d1[0]-d2[9],d2[0]-d1[9]));
    if(an>now){
        now=an;
        j=len-1;
        for(i=0;i<tmp;i++){
            an1[j]=an2[j]='0';
            j--;
            d1[0]--,d2[0]--;
        }
        an1[j]=x+'0';
        an2[j]=y+'0';
        j--;
        for(i=0;i<=9;i++){
            while(d1[i]>0&&d2[9-i]>0){
                an1[j]=i+'0';
                an2[j]=9-i+'0';
                d1[i]--;
                d2[9-i]--;
                j--;
            }
        }
        int k1=0,k2=0;
        for(;j>=0;j--){
            while(d1[k1]==0)k1++;
            d1[k1]--;
            an1[j]=k1+'0';
            while(d2[k2]==0)k2++;
            an2[j]=k2+'0';
            d2[k2]--;
        }
    }
}
int main(){
    int i,j,k;
    gets(s);
    len=strlen(s);
    for(i=0;s[i];i++)
        d[s[i]-'0']++;
    now=d[0];
    for(i=0,j=len-1;i<10;i++){
        for(k=0;k<d[i];k++){
            an1[j]=an2[j]='0'+i;
            j--;
        }
    }
    test(1,9);
    test(2,8);
    test(3,7);
    test(4,6);
    test(5,5);
    printf("%s\n%s\n",an1,an2);
    return 0;
}
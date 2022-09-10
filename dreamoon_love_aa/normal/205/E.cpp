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
#define SIZE 200010
char s1[SIZE],s2[SIZE];
long long cal[SIZE][26],cal2[SIZE][26];
int main(){
    int i,j,k,n;
    long long qq=0;
    scanf("%d%s%s",&n,s1,s2);
    for(i=1;i<=n;i++)qq+=(long long)i*i;
    cal[0][s2[0]-'A']=1;
    for(i=1;i<n;i++){
        for(j=0;j<26;j++)cal[i][j]=cal[i-1][j];
        cal[i][s2[i]-'A']+=i+1;
    }
    cal2[n-1][s2[n-1]-'A']=1;
    for(i=n-2;i>=0;i--){
        for(j=0;j<26;j++)cal2[i][j]=cal2[i+1][j];
        cal2[i][s2[i]-'A']+=n-i;
    }
    long double res=0;
    for(i=0;i<n;i++){
        res+=(i+1)*cal2[i][s1[i]-'A'];
        if(i)res+=(n-i)*cal[i-1][s1[i]-'A'];
    }
    printf("%.12lf\n",(double)(res/qq));
    return 0;
}
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
int d[128];
char s[1000001];
int main(){
    int i,j,k,n;
    gets(s);
    for(i=0;s[i];i++)d[s[i]]++;
    k=min(d['x'],d['y']);
    for(i=0;i<d['x']-k;i++)printf("x");
    for(i=0;i<d['y']-k;i++)printf("y");
    puts("");
    return 0;
}
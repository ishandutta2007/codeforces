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
    int i,j,k=0,n;
    char s[222];
    gets(s);
    set<char>H;
    for(i=0;s[i];i++){
        if(!H.count(s[i]))k^=1;
        H.insert(s[i]);
    }
    if(!k)puts("CHAT WITH HER!");
    else puts("IGNORE HIM!");
    return 0;
}
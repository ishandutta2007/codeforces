#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char s[100005],t[100005];
int main() {
    scanf("%s",s);
    int l=strlen(s),len=0,cnt=0;
    for(int i=l-1;i>=0;i--){
        if(s[i]=='0') t[i]='0',len++;
        else{
            if(len==cnt) t[i]='0',len++;
            else t[i]='1';
            cnt++;
        }
    }
    for(int i=0;i<l;i++) printf("%c",t[i]);
    return 0;
}
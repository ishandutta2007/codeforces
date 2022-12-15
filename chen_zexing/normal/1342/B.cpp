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
#define hash hassh
using namespace std;
char s[105];
int main() {
    int T;
    cin>>T;
    while(T--){
        scanf("%s",s);
        int f=0;
        for(int i=1;i<strlen(s);i++) if(s[i]!=s[0]) f=1;
        if(!f){
            printf("%s\n",s);
            continue;
        }
        for(int i=0;i<strlen(s);i++) printf("01");
        printf("\n");
    }
    return 0;
}
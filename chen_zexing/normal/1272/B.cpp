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
char s[100005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        int cnt[4]={};
        for(int i=0;i<l;i++){
            if(s[i]=='U') cnt[0]++;
            else if(s[i]=='D') cnt[1]++;
            else if(s[i]=='L') cnt[2]++;
            else if(s[i]=='R') cnt[3]++;
        }
        int c1=min(cnt[0],cnt[1]),c2=min(cnt[2],cnt[3]);
        if(c1==0&&c2==0){
            puts("0");
            continue;
        }
        else if(c1==0){
            printf("%d\n",2);
            puts("LR");
            continue;
        }
        else if(c2==0){
            printf("%d\n",2);
            puts("UD");
            continue;
        }
        printf("%d\n",2*(c1+c2));
        for(int i=1;i<=c1;i++) printf("U");
        for(int i=1;i<=c2;i++) printf("L");
        for(int i=1;i<=c1;i++) printf("D");
        for(int i=1;i<=c2;i++) printf("R");
        puts("");
    }
    return 0;
}
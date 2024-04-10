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
char s[105];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        scanf("%s",s+1);
        int l=strlen(s+1),st=-1,ed=-1;
        for(int i=1;i<=l;i++)
            if(s[i]=='1'){
                st=i;
                break;
            }
        for(int i=l;i>=1;i--)
            if(s[i]=='1'){
                ed=i;
                break;
            }
        if(st==-1){
            puts("0");
            continue;
        }
        int ans=0;
        for(int i=st;i<=ed;i++)
            if(s[i]=='0')
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
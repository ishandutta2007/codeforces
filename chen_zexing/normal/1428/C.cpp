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
char s[300005];
int dp[300005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        scanf("%s",s);
        int l=strlen(s),ans=0;
        int pos=l-1;
        while(s[pos]=='A') pos--,ans++;
        int rest=0;
        for(int i=pos;i>=0;i--){
            if(s[i]=='B') rest++;
            else{
                if(rest) rest--;
                else ans++;
            }
        }
        ans+=rest%2;
        printf("%d\n",ans);
    }
    return 0;
}
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
//#include <unordered_map>
#include <map>
#include <stack>
//#include <unordered_set>
#define hash hassh
using namespace std;
char s[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        int cnt1=0,cnt2=0,ans1=0,ans2=0;
        for(int i=0;i<l;i++){
            if(s[i]=='(') cnt1++;
            if(s[i]==')'){
                if(cnt1){
                    cnt1--;
                    ans1++;
                }
            }
            if(s[i]=='[') cnt2++;
            if(s[i]==']'){
                if(cnt2){
                    cnt2--;
                    ans2++;
                }
            }
        }
        printf("%d\n",ans1+ans2);
    }
    return 0;
}
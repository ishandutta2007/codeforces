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
        int n,now;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(i==1){
                now=s[i]-'0'+1;
                printf("1");
                continue;
            }
            if(now==2){
                now=1;
                printf("%d",1-(s[i]-'0'));
            }
            else if(now==1){
                if(s[i]=='1'){
                    printf("1");
                    now=2;
                }
                else{
                    printf("0");
                    now=0;
                }
            }
            else{
                printf("1");
                now=s[i]-'0'+1;
            }
        }
        puts("");
    }
    return 0;
}
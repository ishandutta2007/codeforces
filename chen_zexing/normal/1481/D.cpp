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
char s[1005][1005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        if(n==2){
            if(m%2){
                puts("YES");
                for(int i=1;i<=m+1;i++) printf("%d ",i%2+1);
                puts("");
            }
            else{
                if(s[1][2]==s[2][1]){
                    puts("YES");
                    for(int i=1;i<=m+1;i++) printf("%d ",i%2+1);
                    puts("");
                }
                else puts("NO");
            }
            continue;
        }
        int st;
        if(s[1][2]==s[2][3]) st=3;
        else if(s[2][3]==s[3][1]) st=1;
        else st=2;
        puts("YES");
        st+=(m-1)%3;
        if(st>3) st-=3;
        for(int i=1;i<=m+1;i++){
            printf("%d ",st++);
            if(st>3) st-=3;
        }
        puts("");
    }
    return 0;
}
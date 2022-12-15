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
char s[5005];
struct pos{
    int x,y;
}a[5005],b[5005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s);
        int l=strlen(s);
        for(int i=l;i>=1;i--) s[i]=s[i-1];
        for(int i=1;i<=l;i++){
            a[i].x=a[i-1].x,a[i].y=a[i-1].y;
            if(s[i]=='U') a[i].y++;
            else if(s[i]=='L') a[i].x--;
            else if(s[i]=='D') a[i].y--;
            else a[i].x++;
        }
        int f=0;
        for(int i=1;i<=l;i++){
            int x=a[i].x,y=a[i].y;
            for(int j=1;j<=l;j++){
                b[j].x=b[j-1].x,b[j].y=b[j-1].y;
                if(s[j]=='U') b[j].y++;
                else if(s[j]=='L') b[j].x--;
                else if(s[j]=='D') b[j].y--;
                else b[j].x++;
                if(b[j].x==x&&b[j].y==y){
                    b[j].x=b[j-1].x,b[j].y=b[j-1].y;
                }
            }
            if(b[l].x==0&&b[l].y==0){
                printf("%d %d\n",x,y);
                f=1;
                break;
            }
        }
        if(!f) puts("0 0");
    }
    return 0;
}
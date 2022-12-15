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
char s[405][405];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        int x1=0,y1=0,x2=0,y2=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(s[i][j]=='*'){
                    if(!x1) x1=i,y1=j;
                    else x2=i,y2=j;
                }
        if(x1!=x2&&y1!=y2) s[x1][y2]=s[x2][y1]='*';
        else if(x1==x2){
            if(x1!=n) s[x1+1][y1]=s[x1+1][y2]='*';
            else s[x1-1][y1]=s[x1-1][y2]='*';
        }
        else{
            if(y1!=n) s[x1][y1+1]=s[x2][y2+1]='*';
            else s[x1][y1-1]=s[x2][y2-1]='*';
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                printf("%c",s[i][j]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
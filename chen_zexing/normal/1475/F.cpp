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
char s[1005][1005],t[1005][1005];
int f1[1005],f2[1005],n;
void output(){
    for(int i=1;i<=n;i++) printf("%d",f1[i]);
    for(int i=1;i<=n;i++) printf("%d",f2[i]);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++) scanf("%s",t[i]+1);
        int f=0;
        f1[1]=0;
        if(s[1][1]!=t[1][1]) f2[1]=1;
        else f2[1]=0;
        for(int i=2;i<=n;i++){
            if(s[i][1]!=t[i][1]) f1[i]=1^f2[1];
            else f1[i]=f2[1];
        }
        for(int i=2;i<=n;i++){
            if(s[1][i]!=t[1][i]) f2[i]=1^f1[1];
            else f2[i]=f1[1];
        }
        int fl=1;
        for(int i=2;i<=n;i++)
            for(int j=2;j<=n;j++)
            {
                if(s[i][j]!=t[i][j]&&(f1[i]+f2[j])%2==0) fl=0;
                if(s[i][j]==t[i][j]&&(f1[i]+f2[j])%2) fl=0;
            }
        if(fl){
            f=1;
            //output();
        }
        f1[1]=1;
        if(s[1][1]==t[1][1]) f2[1]=1;
        else f2[1]=0;
        for(int i=2;i<=n;i++){
            if(s[i][1]!=t[i][1]) f1[i]=1^f2[1];
            else f1[i]=f2[1];
        }
        for(int i=2;i<=n;i++){
            if(s[1][i]!=t[1][i]) f2[i]=1^f1[1];
            else f2[i]=f1[1];
        }
        fl=1;
        for(int i=2;i<=n;i++)
            for(int j=2;j<=n;j++)
            {
                if(s[i][j]!=t[i][j]&&(f1[i]+f2[j])%2==0) fl=0;
                if(s[i][j]==t[i][j]&&(f1[i]+f2[j])%2) fl=0;
            }
        if(fl){
            f=1;
            //output();
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
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
char s[305][305];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        int tot=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(s[i][j]=='O'||s[i][j]=='X')
                    tot++;
        int f=0;
        for(int x=0;x<3&&!f;x++)
            for(int y=0;y<3&&!f;y++){
                if(x==y) continue;
                int cnt=0;
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=n;j++)
                        if(s[i][j]=='X'&&(i+j)%3==x||s[i][j]=='O'&&(i+j)%3==y)
                            cnt++;
                if(cnt<=tot/3){
                    f=1;
                    for(int i=1;i<=n;i++,puts(""))
                        for(int j=1;j<=n;j++){
                            if(s[i][j]=='X'&&(i+j)%3==x) s[i][j]='O';
                            if(s[i][j]=='O'&&(i+j)%3==y) s[i][j]='X';
                            printf("%c",s[i][j]);
                        }
                }
            }
    }
    return 0;
}
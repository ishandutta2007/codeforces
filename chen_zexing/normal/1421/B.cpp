#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
char s[205][205];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        int ans=0;
        if(s[1][3]==s[2][2]&&s[2][2]==s[3][1]){
            int t=1-(s[1][3]-'0');
            t+='0';
            if(s[1][2]!=t) ans++;
            if(s[2][1]!=t) ans++;
            printf("%d\n",ans);
            if(s[1][2]!=t) printf("1 2\n");
            if(s[2][1]!=t) printf("2 1\n");
        }
        else if(s[1][2]==s[2][1]){
            int t=1-(s[1][2]-'0');
            t+='0';
            if(s[1][3]!=t) ans++;
            if(s[2][2]!=t) ans++;
            if(s[3][1]!=t) ans++;
            printf("%d\n",ans);
            if(s[1][3]!=t) printf("1 3\n");
            if(s[2][2]!=t) printf("2 2\n");
            if(s[3][1]!=t) printf("3 1\n");
        }
        else{
            printf("2\n");
            int t=s[1][3]+s[2][2]+s[3][1]-'0'*3;
            if(t==2){
                t=1;
                t+='0';
                if(s[1][3]!=t) printf("1 3\n");
                if(s[2][2]!=t) printf("2 2\n");
                if(s[3][1]!=t) printf("3 1\n");
                t=0;
                t+='0';
                if(s[1][2]!=t) printf("1 2\n");
                if(s[2][1]!=t) printf("2 1\n");
            }
            else{
                t=0;
                t+='0';
                if(s[1][3]!=t) printf("1 3\n");
                if(s[2][2]!=t) printf("2 2\n");
                if(s[3][1]!=t) printf("3 1\n");
                t=1;
                t+='0';
                if(s[1][2]!=t) printf("1 2\n");
                if(s[2][1]!=t) printf("2 1\n");
            }
        }
    }
    return 0;
}
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
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%s",s);
        int l=strlen(s);
        int c1=0,c2=0,c3=0,c4=0;
        for(int i=0;i<l;i++){
            if(s[i]=='U') c1++;
            else if(s[i]=='D') c2++;
            else if(s[i]=='R') c3++;
            else c4++;
        }
        int f=1;
        if(x>0){
            if(c3<x) f=0;
        }
        else{
            if(c4<abs(x)) f=0;
        }
        if(y>0){
            if(c1<y) f=0;
        }
        else{
            if(c2<abs(y)) f=0;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
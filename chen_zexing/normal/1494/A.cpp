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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        char s[55];
        scanf("%s",s);
        int l=strlen(s),fl=0;
        for(int i=0;i<8;i++){
            int c[3]={};
            for(int j=0;j<3;j++) c[j]=((1<<j)&i)>0;
            int f=1,now=0;
            for(int j=0;j<l;j++){
                if(c[s[j]-'A']) now++;
                else now--;
                if(now<0) f=0;
            }
            if(now) f=0;
            if(f) fl=1;
        }
        if(fl) puts("YES");
        else puts("NO");
    }
    return 0;
}
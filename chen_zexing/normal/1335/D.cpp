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
char s[15][15];
int x[10]={1,4,7,2,5,8,3,6,9},y[10]={1,2,3,4,5,6,7,8,9};
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        for(int i=1;i<=9;i++) scanf("%s",s[i]+1);
        for(int i=0;i<9;i++) s[x[i]][y[i]]=(s[x[i]][y[i]]-'0')%9+1+'0';
        for(int i=1;i<=9;i++,puts(""))
            for(int j=1;j<=9;j++)
                printf("%c",s[i][j]);
    }
    return 0;
}
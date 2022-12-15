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
char s[55][55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        int f=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(s[i][j]=='1'&&i!=n&&j!=n&&(s[i+1][j]=='0'&&s[i][j+1]=='0')) f=0;
            }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
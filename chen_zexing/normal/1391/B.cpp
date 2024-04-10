#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
char s[105][105];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<n;i++)
            if(s[i][m]!='D') ans++;
        for(int i=1;i<m;i++)
            if(s[n][i]!='R') ans++;
        printf("%d\n",ans);
    }
    return 0;
}
#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[200005];
int ans[200005];
vector <int> a[30];
int main() {
    int n, x = 1;
    cin >> n;
    scanf("%s", s + 1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(a[j].size()==0||s[a[j][a[j].size()-1]]<=s[i]){
                a[j].push_back(i);
                break;
            }
        }
        if(s[a[x][a[x].size()-1]]>s[i])
            a[++x].push_back(i);
    }
    printf("%d\n",x);
    for(int i=1;i<=x;i++)
        for(int j=0;j<a[i].size();j++)
            ans[a[i][j]]=i;
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}
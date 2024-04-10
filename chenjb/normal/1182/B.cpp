#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#define mp make_pair
#define pb push_back
using namespace std;
char s[510][510];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
    int ans=0;
    int sum=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if (s[i][j]=='*')sum++;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if (s[i][j]!='*')continue;
            int cnt1=0,cnt2=0,cnt3=0,cnt4=0;
            for(int p=i+1;p<=n;p++)if (s[p][j]=='*')cnt1++; else break;
            for(int p=i-1;p>=1;p--)if (s[p][j]=='*')cnt2++; else break;
            for(int p=j+1;p<=m;p++)if (s[i][p]=='*')cnt3++; else break;
            for(int p=j-1;p>=1;p--)if (s[i][p]=='*')cnt4++; else break;
            if (cnt1+cnt2+cnt3+cnt4+1!=sum)continue;
            if (cnt1<1||cnt2<1||cnt3<1||cnt4<1)continue;
            ans++;
        }

    if (ans==1)puts("YES"); else puts("NO");
    return 0;
}
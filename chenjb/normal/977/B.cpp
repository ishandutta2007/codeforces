#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <cassert>
#define rep(i,n) for(int i=1;i<=n;++i)
#define mp make_pair
#define pb push_back
#define magic 300
using namespace std;
int a[30][30];
int main()
{
    int n;
    char s[110];
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<n;i++)a[s[i]-'A'][s[i+1]-'A']++;
    int ansx=0,ansy=0;
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            if (a[i][j]>a[ansx][ansy])ansx=i,ansy=j;
    cout<<(char)('A'+ansx)<<(char)('A'+ansy)<<endl;
}
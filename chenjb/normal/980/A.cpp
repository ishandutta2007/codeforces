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
using namespace std;
int n,k;
char s[500];
int main()
{
    scanf("%s",s+1);
    int a=0,b=0;
    for(int i=1;i<=strlen(s+1);i++)if (s[i]=='-')a++; else b++;
    if (b==0 || a%b==0)puts("YES"); else puts("NO");
    return 0;
}
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
char s[110];
int main()
{
    int k;
    scanf("%s%d",s+1,&k);
    for(int i=1;i<=k;i++)
    {
        if (s[strlen(s+1)]=='0')s[strlen(s+1)]=0;
        else s[strlen(s+1)]--;
    }
    printf("%s",s+1); puts("");
    return 0;
}
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
#define POVAR 1488228228
#define X first
#define Y second
using namespace std;

int a[100100], ans, n, m, k;
int main()
{
            cin >> n >> m >> k;
    for (int i=1; i<=m + 1; i++)
                cin>>a[i];
    for (int i=1; i<=m; i++)
                    ans+=(__builtin_popcount(a[i] ^ a[m+1])<=k);
        cout<<ans<<endl;
            return 228/1488;
}
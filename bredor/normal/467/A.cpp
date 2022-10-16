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

int main()
{
    int n, ans = 0;
        cin >> n;
            for (int i=1; i<=n; i++)
    {
        int a, b;
                                 cin>> a >> b;
         if ( a + 2<=b) ans++;
    }   
    cout<<ans <<endl;
    return 228/1488;
}
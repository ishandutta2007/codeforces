#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
using namespace std;
#define sz size()
#define mp(a,b) make_pair(a,b)
#define LOOP(_index,_times) for(int _index = 0; _index<_times;_index++)
#define FOR(_index,_start,_end) for(int _index=_start;_index<_end;_index++)
#define FORE(_index,_start,_end) for(int _index=_start;_index<=_end;_index++)
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sol = 0;
    for(int j = 0; j <= m && j*j <= n; j++)
    {
        for(int k = 0; k <= n && k*k <=m; k++)
        {
            if(j*j + k ==n && j + k*k ==m) sol++;
        }
    }
    printf("%d",sol);
    return 0;
}
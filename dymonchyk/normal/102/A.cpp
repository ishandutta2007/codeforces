#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stack>
#include <ctime>
#pragma comment(linker,"/STACK:64000000")

#define ll long long

using namespace std;

int a[101][101],p[101];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,c,b;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> p[i];
    for(int i=0;i<m;i++)
    {
        cin >> b >> c;
        a[b-1][c-1]=a[c-1][b-1]=1;
    }
    int ans=-1;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int t=j+1;t<n;t++)
                if (a[i][j]&&a[j][t]&&a[i][t]&&(ans==-1||ans>p[i]+p[j]+p[t])) ans=p[i]+p[j]+p[t];
    cout << ans << endl;
    return 0;
}
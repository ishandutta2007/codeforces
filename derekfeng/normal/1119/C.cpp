#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bitset>
#include <ios> 
#include <bits/stdc++.h>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma G++ optimize(3)
#pragma G++ optimize(4)
#pragma G++ optimize(5)
#pragma G++ optimize(6)
#pragma G++ optimize(7)
#pragma G++ optimize(8)
#pragma GCC optimize(9)
using namespace std;
int n,m;
bool a[505][505];
bool b[505][505];
int d[505][505];
int r[505],c[505];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>b[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            d[i][j]=(a[i][j]!=b[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            r[i]+=d[i][j];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            c[j]+=d[i][j];
    for(int i=1;i<=n;i++)
        if(r[i]%2==1){
            puts("No");
            return 0;
        }
    for(int j=1;j<=m;j++)
        if(c[j]%2==1){
            puts("No");
            return 0;
        }
    puts("Yes");
    return 0;
}
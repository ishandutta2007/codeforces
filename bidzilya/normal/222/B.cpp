#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

const int NMAX = 1000;

int c[1000],r[1000],a[1000][1000];
int n,m,k;

int main(){
    cin >> n >> m >> k;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin >> a[i][j];
    for (int i=0;i<n;i++)r[i]=i;
    for (int i=0;i<m;i++)c[i]=i;
    for (;k;k--){
        char cmd;
        int v1,v2;
        cin >> cmd >> v1 >> v2;
        v1--;v2--;
        if (cmd=='c')swap(c[v1],c[v2]);
        else
        if (cmd=='r')swap(r[v1],r[v2]);
        else{
             v1 = r[v1];
             v2 = c[v2];
             cout << a[v1][v2] << endl;
        }
    }
    return 0;
}
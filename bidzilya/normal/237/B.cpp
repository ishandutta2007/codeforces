#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n;
int sz[50];
vector<int> p1,q1,p2,q2;
int a[2501][2];
int b[50][50];

int main(){
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> sz[i];
    for (int i=0;i<n;i++)
        for (int j=0;j<sz[i];j++){
            cin >> b[i][j];
            a[b[i][j]][0] = i;
            a[b[i][j]][1] = j;
        }
    int cur = 1;
    for (int i=0;i<n;i++)
        for (int j=0;j<sz[i];j++){
            int buf = b[i][j];
            if (buf==cur){cur++;continue;}
            p1.push_back(i);
            q1.push_back(j);
            p2.push_back(a[cur][0]);
            q2.push_back(a[cur][1]);
            b[a[cur][0]][a[cur][1]]=buf;
            a[buf][0]=a[cur][0];
            a[buf][1]=a[cur][1];
            cur++;
        }
    cout << p1.size() << endl;
    for (int i=0;i<p1.size();i++)
        cout << (p1[i]+1) << " " << (q1[i]+1) << " " << (p2[i]+1) << " " << (q2[i]+1) << endl;
    return 0;
}
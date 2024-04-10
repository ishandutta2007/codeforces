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

int main(){
    int a,b,x,y;
    cin >> x >> y >> a >> b;
    vector<pair<int,int> > g;
    for (int i=0;i<=x;i++)
        for (int j=0;j<min(i,y+1);j++)
            if (i>=a && j>=b)
                g.push_back(make_pair(i,j));
    cout << g.size() << endl;
    for (int i=0;i<g.size();i++)
        cout << g[i].first << " " << g[i].second << endl;

    return 0;
}
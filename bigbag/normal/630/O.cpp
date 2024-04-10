#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const long double pi = 2 * acos((long double) (0));

long double px, py, vx, vy, a, b, c, d;
vector<pair<long double, long double> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    ans.push_back(make_pair(a / 2, 0));
    ans.push_back(make_pair(c / 2, 0));
    ans.push_back(make_pair(c / 2, -d));
    ans.push_back(make_pair(-c / 2, -d));
    ans.push_back(make_pair(-c / 2, 0));
    ans.push_back(make_pair(-a / 2, 0));
    ans.push_back(make_pair(0, b));
    long double ang = pi / 2 - atan2(vy, vx);
    //printf("%.10f\n", (double) ang);
    for (int i = ans.size() - 1; i >= 0; --i) {
        long double nx, ny, x, y;
        x = ans[i].first;
        y = ans[i].second;
        nx = x * cos(ang) + y * sin(ang);
        ny = -x * sin(ang) + y * cos(ang);
        printf("%.10f ", (double) (nx + px));
        printf("%.10f\n", (double) (ny + py));
    }
    return 0;
}
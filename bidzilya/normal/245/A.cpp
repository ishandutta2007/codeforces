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
#include <deque>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int norm[2],fail[2];
int x,y,n,k;

int main(){
    for (int i=0;i<2;i++)
        norm[i]=fail[i]=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> k >> x >> y;
        k--;
        norm[k] += x;
        fail[k] += y;
    }
    for (int i=0;i<2;i++)
        if (norm[i]>=fail[i])
            cout << "LIVE" << endl;
        else
            cout << "DEAD" << endl;

    return 0;
}
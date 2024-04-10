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

int main(){
    int n;
    int b[100][100];
    cin >> n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin >> b[i][j];
    for (int i=0;i<n;i++){
        int a = 0;
        for (int j=0;j<n;j++)
            if (i!=j)
                a |= b[i][j];
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
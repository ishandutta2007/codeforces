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
const ll MD = (ll)1e9 + 9;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n;
vector<int> a,b;

int main(){
    cin >> n;
    a.resize(n);
    for (int i=0;i<n;i++)
        cin >> a[i];
    int cnt = (a[0] < 0);
    b.push_back(1);
    for (int i=1;i<n;i++)
    {
        if (a[i] >= 0)
            b[b.size()-1]++;
        else
        {
            cnt++;
            if (cnt == 3)
            {
                b.push_back(1);
                cnt = 1;
            }else
                b[b.size()-1]++;
        }
    }
    cout << b.size() << endl;
    for (int i=0;i<b.size();i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;
}
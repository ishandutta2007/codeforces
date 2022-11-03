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
int nl,nr;
int l[111111],r[111111];

int main(){
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> l[i] >> r[i];
    nl = nr = 1;
    for (int i=1;i<=n;i++){
        if (l[i]<l[nl] || (l[i]==l[nl] && r[i]>r[nl]))
            nl = i;
        if (r[i]>r[nr])
            nr = i;
    }
    if (r[nl]==r[nr])
        cout << nl;
    else
        cout << -1;
    cout << endl;
    return 0;
}
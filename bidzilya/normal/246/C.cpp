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

int n,k;
int a[50];

int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    for (int len=1;len<=n;len++)
        for (int j=n-len;j>=0;j--){
            cout << len << " ";
            for (int i=n-1;i>n-len;i--)
                cout << a[i] << " ";
            cout << a[j] << endl;
            k--;
            if (!k)return 0;
        }
}
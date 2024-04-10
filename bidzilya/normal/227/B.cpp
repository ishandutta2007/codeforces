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

int n;
int a[100001];
int p[100000];
int x,m;

int main(){
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        a[x]=i+1;
    }
    cin >> m;
    for (int i=0;i<m;i++) cin >> p[i];
    ll s1= 0;
    for (int i=0;i<m;i++) s1 += a[p[i]];
    ll s2=0;
    for (int i=0;i<m;i++) s2 += (n-a[p[i]]+1);
    cout << s1 << " " << s2 << endl;
//    system("pause");
    return 0;
}
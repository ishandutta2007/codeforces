#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#define mp make_pair
#define pb push_back
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    long long sum = 0;
    vector<int> a(n) , b(n);
    for(int i = 0; i < n; i++) cin >> a[i]  , sum += a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(b.rbegin() , b.rend());
    if(b[0] + b[1] >= sum)
    {
        cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
}
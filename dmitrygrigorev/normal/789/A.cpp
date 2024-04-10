#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
using namespace std;
long long n, k, ai;
vector<long long> data;
int main()
{
    cin >> n >> k;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    long long ans = 0;
    for (int i=0;i<n;i++){
        if (data[i] % k == 0) ans += data[i] / k;
        else ans += data[i] / k + 1;
    }
    if (ans % 2 == 0) cout << ans / 2 << endl;
    else cout << ans / 2 + 1 << endl;
    return 0;
}
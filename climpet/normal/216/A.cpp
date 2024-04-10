#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <iterator>
#include <sstream>
#include <cstring>

using namespace std;


typedef long long LL;


int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int z = 7;
    z += (a - 2) * 3;
    z += (b - 2) * (a + 1);
    z += (c - 2) * (a + b - 1);
    cout << z << endl;
}
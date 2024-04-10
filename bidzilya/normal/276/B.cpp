#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#ifndef ONLINE_JUDGE
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

string s;
int a[26];
int n;

int main() {
    getline(cin, s);
    for (int i = 0; i < (int) s.length(); ++i)
        ++a[s[i] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (a[i] % 2 == 1)
            ++n;
    if (n == 0 || n == 1 || n % 2 == 1)
        cout << "First";
    else
        cout << "Second";
    cout << endl;
        
    return 0;
}
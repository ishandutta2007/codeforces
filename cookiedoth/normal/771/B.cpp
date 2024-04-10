/**********
*         *
*  HELLO  *
*         *
**********/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdlib>
#include <stdio.h>
#define ll long long
#define mp make_pair
#define MOD 1000000007

using namespace std;

int n, k, a[100];

void get (int x) {
    string res = "";
    char c1 = (x / 26) + 65;
    char c2 = (x % 26) + 97;
    cout << c1 << c2 << " ";
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < (k-1); ++i) {
        a[i] = i;
    }
    string s;
    for (int i = (k-1); i < n; ++i) {
        cin >> s;
        if (s == "YES") {
            a[i] = i;
        }
        else {
            a[i] = a[i-k+1];
        }
    }
    for (int i = 0; i < n; ++i) {
        get(a[i]);
    }
    return 0;
}
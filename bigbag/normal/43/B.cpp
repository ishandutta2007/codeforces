#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

int used1[2222], used2[2222];
string s1, s2;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    getline(cin, s1);
    getline(cin, s2);
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != ' ') {
            used1[s1[i]]++;
        }
    }
    for (int i = 0; i < s2.length(); ++i) {
        if (s2[i] != ' ') {
            used2[s2[i]]++;
        }
    }
    for (int i = 20; i < 1111; ++i) {
        if (used2[i] > used1[i]) {
            //printf("%c ", i);
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
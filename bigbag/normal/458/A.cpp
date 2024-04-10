#include <map>
#include <set>
#include <stack>
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

string s1, s2;
int l1, l2, l;

char fun(int p) {
    if (p == l) {
        return '=';
    }
    if (s1[p] == s2[p]) {
        return fun(p + 1);
    }
    if (s1[p] == '0') {
        if (p + 1 == l) {
            return '<';
        }
        if (s1[p + 1] == '0' || s1[p + 1] == s2[p + 1]) {
            return '<';
        }
        if (p + 2 == l) {
            return '<';
        }
        if (s2[p + 2] == s1[p + 2]) {
            s1[p + 2] = s2[p + 2] = '0';
        }
        if (s2[p + 2] == '1') {
            return '<';
        }
        s2[p + 2] = '1';
        return fun(p + 2);
    } else {
        if (p + 1 == l) {
            return '>';
        }
        if (s2[p + 1] == '0' || s1[p + 1] == s2[p + 1]) {
            return '>';
        }
        if (p + 2 == l) {
            return '>';
        }
        if (s2[p + 2] == s1[p + 2]) {
            s1[p + 2] = s2[p + 2] = '0';
        }
        if (s1[p + 2] == '1') {
            return '>';
        }
        s1[p + 2] = '1';
        return fun(p + 2);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> s1 >> s2;
    l1 = s1.length();
    l2 = s2.length();
    if (l1 < l2) {
        string q = "";
        while (l1 < l2) {
            ++l1;
            q += "0";
        }
        s1 = q + s1;
    }
    if (l2 < l1) {
        string q = "";
        while (l2 < l1) {
            ++l2;
            q += "0";
        }
        s2 = q + s2;
    }
    //cout << s1 << endl << s2 << endl;
    l = l1;
    cout << fun(0) << endl;
    return 0;
}
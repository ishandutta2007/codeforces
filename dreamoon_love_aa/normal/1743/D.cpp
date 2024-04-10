#include<iostream>
using namespace std;
int n;
string s;
int main() {
    cin >> n >> s;
    string an = s;
    for(int i = 1; i < 30; i++) {
        string t = s;
        for(int j = i; j < n; j++) t[j] |=  s[j - i];
        if(an < t) an = t;
    }
    int st = 0;
    while(st < n - 1 && s[st] == '0') st++;
    cout << an.substr(st) << '\n';
    return 0;
}
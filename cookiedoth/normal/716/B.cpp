/************
*           *
*   HELLO   *
*           *
************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s.length()<26) {
        cout << -1;
        return 0;
    }
    int i, k, d, e, a[26], j, b;
    char c;
    k = 0;
    d = 0;
    for (i = 0; i<26; i++) {
        a[i] = 0;
    }
    for (i = 0; i<26; i++) {
        if (s[i] != '?') {
            c = s[i];
            e = c - 65;
            if (a[e] == 0) {
                d++;
            }
            a[e]++;
        }
        else {
            k++;
        }
    }
    i = 25;
    while ((k+d<26)&&(i<s.length())) {
        i++;
        if (s[i-26] == '?') k--;
        else
        {
          c = s[i-26];
          e = c - 65;
          a[e]--;
          if (a[e] == 0) {
            d--;
          }
        }
        if (s[i] == '?') k++;
        else
        {
          c = s[i];
          e = c - 65;
          a[e]++;
          if (a[e] == 1) {
            d++;
          }
        }
    }
    if (k+d<26) {
        cout << -1;
        return 0;
    }
    for (j = 0; j<=i-26; j++) {
        if (s[j] != '?') {
            cout << s[j];
        }
        else {
            cout << "A";
        }
    }
    for (j = i-25; j<=i; j++) {
        if (s[j] != '?') cout << s[j];
        else {
            for (b = 0; b<26; b++) {
                if (a[b] == 0) {
                    a[b] = 1;
                    c = b + 65;
                    cout << c;
                    break;
                }
            }
        }
    }
    for (j = i+1; j<s.length(); j++) {
        if (s[j] != '?') {
            cout << s[j];
        }
        else {
            cout << "A";
        }
    }
    return 0;
}
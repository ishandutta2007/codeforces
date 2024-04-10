#include <bits/stdc++.h>

#define rd(x) x = read()

using namespace std;

int l;
string s;

void pre(string &s1, string &s2) {
    while (s1.length() < s2.length()) s1 = '0' + s1;
    while (s2.length() < s1.length()) s2 = '0' + s2;
}

string clearZero(string s) {
    while (s.length() > 0 && s[0] == '0') s.erase(0, 1);
    return s;
}

string add(string s1, string s2) {
    int i;
    string result;
    pre(s1, s2);
    s1 = '0' + s1;
    s2 = '0' + s2;
    int l1 = s1.length();
    for (i = l1 - 1; i >= 0; i--) {
        s1[i] += s2[i] - '0';
        if (s1[i] > '9') {
            s1[i] -= 10;
            s1[i - 1]++;
        }
    }
    result = clearZero(s1);
    return result;
}

string cmp(string s1, string s2) {
    if (s1.length() > s2.length())
        return s2;
    if (s1.length() == s2.length() && s1 >= s2)
        return s2;
    return s1;
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch > '9' || ch < '0') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

inline void write(int x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x >= 10)
        write(x / 10);
    putchar(x % 10 + '0');
}

string calc(string s) {
    int mid = (l - 1) / 2, mid1 = -1, mid2 = -1;
    if (s[mid + 1] == '0') {
        //		cout<<mid<<endl;
        for (int i = mid + 1; i < l; i++)
            if (s[i + 1] != '0') {
                mid1 = i;
                break;
            }
        for (int i = mid - 1; i >= 0; i--)
            if (s[i + 1] != '0') {
                mid2 = i;
                break;
            }
    } else
        mid1 = mid, mid2 = mid - 1;
    string ans1 = "", ans2 = "";
    if (mid1 != -1) {
        string s1 = s.substr(0, mid1 + 1), s2 = s.substr(mid1 + 1, l - mid1 - 1);
        ans1 = add(s1, s2);
    }
    //	cout<<s1<<' '<<s2<<endl;

    if (s[mid2 + 1] != '0' && mid2 != -1) {
        string s3 = s.substr(0, mid2 + 1), s4 = s.substr(mid2 + 1, l - mid2 - 1);
        ans2 = add(s3, s4);
    }
    if (ans1 == "")
        cout << ans2 << endl;
    else if (ans2 == "")
        cout << ans1 << endl;
    else
        cout << cmp(ans1, ans2) << endl;
}

int main() {
    rd(l);
    cin >> s;
    calc(s);

    return 0;
}
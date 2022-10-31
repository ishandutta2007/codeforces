#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

typedef long long ll;

int max(int a, int b)
{ return (a > b) ? a : b; }

const int MAXN = 1031;

int a[10];

vector<int> prefix_function (string s)
{
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i)
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}

int cnt[2];
int needT[2];
int needTsuf[2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;

    cin >> s;
    for (char c : s)
    {
        cnt[c - '0']++;
    }

    cin >> t;
    for (char c : t)
    {
        needT[c - '0']++;
    }

    vector<int> pi;
    pi = prefix_function(t);
    stringstream ss;
    if (needT[0] <= cnt[0] && needT[1] <= cnt[1]) {
//        cerr << " " << t;
        ss << t;
        cnt[0] -= needT[0];
        cnt[1] -= needT[1];

        int inter = t.length() - pi[t.length() - 1];
        int j = t.length() - inter;
//        cerr << inter << " " << j << endl;
        for (int i = j; i < t.length(); i++) {
            needTsuf[t[i] - '0']++;
        }

        string st = t.substr(j);
        while (cnt[0] >= needTsuf[0] && cnt[1] >= needTsuf[1])
        {
//            cerr << " " << st;
            ss << st;
            cnt[0] -= needTsuf[0];
            cnt[1] -= needTsuf[1];
        }
    }
    while (cnt[0] > 0)
    {
//        cerr << " 0";
        ss << "0";
        cnt[0]--;
    }

    while (cnt[1] > 0)
    {
//        cerr << " 1";
        ss << "1";
        cnt[1]--;
    }

    string q;
    ss >> q;
    cout << q;
    return 0;
}
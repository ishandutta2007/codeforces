#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

#include <cassert>
using namespace std;

const int MIN_YEAR = 1989;
const int MIDDLE_YEAR = 1e5;
const int MAX_YEAR = int(1e9);

string IntToString(int x) {
    if (x == 0) {
        return "0";
    }
    string result;
    while (x > 0) {
        result.push_back((char)(x % 10 + '0'));
        x /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}

int StringToInt(const string& s) {
    int result = 0;
    for (int i = 0; i < (int) s.length(); ++i) {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}

set<string> resultSet;

string GetResult(int x) {
    string s = IntToString(x);
    for (int len = 1; len <= (int) s.length(); ++len) {
        string t = s.substr(s.length() - len, len);

        if (resultSet.find(t) == resultSet.end()) {
            return t;
        }
    }
    assert(false);
}

map<string, int> smallResults;

vector<pair<string, string>> segs;
vector<int> segLen;

const int SEGS_START = MIN_YEAR + 1;

int Solve(const string& s) {
    if (smallResults.find(s) != smallResults.end()) {
        return smallResults[s];
    }
    int start = SEGS_START;
    for (int i = 0; i < (int) segs.size(); ++i) {
        if (s.length() == segs[i].first.length() &&
            s >= segs[i].first && s <= segs[i].second)
        {
            int diff = StringToInt(s) - StringToInt(segs[i].first);
            start += diff;
            return start;
        } else {
            int segLen = StringToInt(segs[i].second) - StringToInt(segs[i].first) + 1;
            start += segLen;
        }
    }
    assert(false);
}

void BuildSmallResults() {
    auto add = [] (const string& s, int x) {
        smallResults[s] = x;
    };
    add("9", 1989);
    add("99", 1999);
    add("099", 2099);
    add("3099", 3099);
    add("13099", 13099);
    add("113099", 113099);
    add("1113099", 1113099);
    add("11113099", 11113099);
    add("111113099", 111113099);

    segs.push_back(make_pair("0", "9"));

    segs.push_back(make_pair("00", "99"));

    segs.push_back(make_pair("100", "999"));
    segs.push_back(make_pair("000", "099"));

    for (int addLen = 0; addLen <= 5; ++addLen) {
        segs.push_back(make_pair("", ""));
        for (int i = 0; i < addLen; ++i) {
            segs.back().first.push_back('1');
            segs.back().second.push_back('9');
        }
        segs.back().first += "3100";
        segs.back().second += "9999";

        segs.push_back(make_pair("", ""));
        for (int i = 0; i < addLen; ++i) {
            segs.back().first.push_back('0');
            segs.back().second.push_back('1');
        }
        segs.back().first += "0000";
        segs.back().second += "3099";
    }
}

void Test() {
    resultSet.clear();
    for (int i = MIN_YEAR; i < MAX_YEAR; ++i) {
        cout << i << endl;
        string r = GetResult(i);

        resultSet.insert(r);

        if (Solve(r) != i) {
            cout << "Fail at i = " << i << endl;
            cout << Solve(r) << endl;
            cout << r << endl;
            return;
        }
    }
    cout << "Ok" << endl;
}

int main() {
    BuildSmallResults();

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c;
        for (int j = 0; j < 4; ++j) {
            cin >> c;
        }
        string s;
        cin >> s;
        cout << Solve(s) << endl;
    }

    return 0;
}
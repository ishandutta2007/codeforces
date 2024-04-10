#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetShifted(const string& s, int start_pos)
{
    int n = s.length();
    string result;
    result.resize(n);
    for (int i = start_pos; i < n; ++i) {
        result[i - start_pos] = s[i];
    }
    for (int i = 0; i < start_pos; ++i) {
        result[n - start_pos + i] = s[i];
    }
    return result;
}

void Up(char& c)
{
    if (c == '9') {
        c = '0';
    } else {
        c = (char) (c + 1);
    }
}

void Up(string& s)
{
    for (int i = 0; i < (int) s.length(); ++i) {
        Up(s[i]);
    }
}

void UpToMinimal(string& s)
{
    while (s[0] != '0') {
        Up(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = s;

    for (int i = 0; i < n; ++i) {
        string cur_shift = GetShifted(s, i);

        UpToMinimal(cur_shift);

        ans = min(ans, cur_shift);
    }

    cout << ans << endl;

    return 0;
}
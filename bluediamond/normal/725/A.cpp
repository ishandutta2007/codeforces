#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int i = 0, j = n - 1;
    while (i < n && s[i] == '<')
    {
        i++;
    }
    while (j >= 0 && s[j] == '>')
    {
        j--;
    }
    cout << n - j + i - 1 << "\n";



}
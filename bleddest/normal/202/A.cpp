#include<iostream>
#include<string>

using namespace std;


int main()
{
    string t;
    cin >> t;
    string ans = "";
    int n = t.size();
    for(int i = 0; i < (1 << n); i++)
    {
        string s = "";
        for(int j = 0; j < n; j++)
            if((i >> j) & 1)
                s += t[j];
        if(s == string(s.rbegin(), s.rend()) && s > ans)
            ans = s;
    }
    cout << ans << endl;
    return 0;
}
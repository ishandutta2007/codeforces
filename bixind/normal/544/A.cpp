#include <iostream>
#include <set>

using namespace std;

int main()
{
    int k, i;
    string s, s1;
    cin >> k >> s;
    set<char> bkv;
    for (i = 0; i < s.size(); i++)
    {
        bkv.insert(s[i]);
    }
    if (bkv.size() < k)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        bkv.clear();
        s1 = s[0];
        bkv.insert(s[0]);
        for (i = 1; i < s.size(); i++)
        {
            if (bkv.find(s[i]) == bkv.end() && k > 1)
            {
                cout << s1 << endl;
                s1 = "";
                bkv.insert(s[i]);
                k--;
            }
            s1.push_back(s[i]);
        }
        cout << s1 << endl;
    }
    return 0;
}
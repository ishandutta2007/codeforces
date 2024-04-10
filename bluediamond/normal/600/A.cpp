#include <bits/stdc++.h>

using namespace std;

bool good(string s)
{
        if (s == "0")
                return 1;
        if (s.empty())
                return 0;
        for (auto &c : s)
                if (c < '0' || '9' < c)
                        return 0;
        if (s[0] == '0')
                return 0;
        else
                return 1;
}

string s;
vector <int> p;

void print(vector <string> a)
{
        if (a.empty())
        {
                cout << "-\n";
                return;
        }
        cout << '"';

        for (int i = 0; i < (int) a.size(); i++)
        {
                cout << a[i];
                if (i != (int) a.size() - 1)
                        cout << ",";
        }

        cout << '"';
        cout << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

        cin >> s;
        int n = (int) s.size();

        p.push_back(-1);
        for (int i = 0; i < n; i++)
                if (s[i] == ',' || s[i] == ';')
                        p.push_back(i);
        p.push_back(n);

        vector <string> a, b;
        for (int i = 0; i + 1 < (int) p.size(); i++)
        {
                string w;
                for (int j = p[i] + 1; j < p[i + 1]; j++)
                        w += s[j];
                if (good(w))
                        a.push_back(w);
                else
                        b.push_back(w);
        }

        print(a);
        print(b);

}
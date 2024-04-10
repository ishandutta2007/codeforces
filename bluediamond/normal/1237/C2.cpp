#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool cmp(vector<int> a, vector<int> b)
{
    return a.back() < b.back();
}

vector<int> print(vector<vector<int>> v)
{
    if ((int) v.size() == 1)
    {
        return v[0];
    }
    sort(v.begin(), v.end(), cmp);
    int n = (int) v.size(), i = 0;
    vector<vector<int>> smuti;
    while (i < n)
    {
        int j = i;
        while (j + 1 < n && v[j + 1].back() == v[j].back())
        {
            j++;
        }
        for (int k = i; k <= j; k++)
        {
            v[k].pop_back();
        }
        vector<vector<int>> v2;
        for (int k = i; k <= j; k++)
        {
            v2.push_back(v[k]);
        }
        vector<int> lol = print(v2);
        if (!lol.empty())
        {
            smuti.push_back(lol);
        }
        i = j + 1;
    }
    vector<int> it = {};
    if ((int) smuti.size() & 1)
    {
        it = smuti.back();
        smuti.pop_back();
    }
    for (int i = 0; i + 1 < (int) smuti.size(); i += 2)
    {
        cout << smuti[i][0] << " " << smuti[i + 1][0] << "\n";
    }
    return it;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int> (4));
    for (int i = 0; i < n; i++)
    {
        v[i][0] = i + 1;
        cin >> v[i][1] >> v[i][2] >> v[i][3];
    }
    print(v);
}
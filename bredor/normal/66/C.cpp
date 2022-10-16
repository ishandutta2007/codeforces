//  228

#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;

map<string, set<string>> folds;
map<string, int> files;

char buf[1000];

void hehe()
{
    int resfiles = 0, resfolds = 0;
    while (scanf("%s", buf) != EOF)
    {
        string s(buf);
        int i = 0, k = 0;
        while (true)
        {
            if (s[i] == '\\')
                k++;
            if (k == 2)
                break;
            i++;
        }
        string x = s.substr(0, i);
        string f = s.substr(i + 1);
        for (int q = 0; q < f.size(); q++)
        {
            if (q && f[q] == '\\')
            {
                string fld = f.substr(0, q);
                folds[x].insert(fld);
                resfolds = max(resfolds, (int)folds[x].size());
            }
        }
        files[x]++;
        resfiles = max(resfiles, files[x]);
    }
    cout << resfolds << " " << resfiles;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        hehe();
    }

    return 0;
}
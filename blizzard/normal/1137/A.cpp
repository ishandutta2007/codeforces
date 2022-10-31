#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int max(int a, int b)
{ return (a > b) ? a : b; }

const int MAXN = 1031;

int a[MAXN][MAXN];
vector<int> b[MAXN];
vector<int> c[MAXN];
int ans[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        b[i].resize(m);
    for (int i = 0; i < m; i++)
        c[i].resize(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
            c[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        sort(b[i].begin(), b[i].end());
        b[i].resize(unique(b[i].begin(), b[i].end()) - b[i].begin());
    }

    for (int i = 0; i < m; i++)
    {
        sort(c[i].begin(), c[i].end());
        c[i].resize(unique(c[i].begin(), c[i].end()) - c[i].begin());
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int index1 = lower_bound(b[i].begin(), b[i].end(), a[i][j]) - b[i].begin();
            int index2 = lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();

            int lessrow = index1;
            int morerow = b[i].size() - index1 - 1;
            int lesscol = index2;
            int morecol = c[j].size() - index2 - 1;

//                int lessrow = lower_bound(b[i].begin(), b[i].end(), a[i][j]) - b[i].begin();
//                int morerow = (b[i].end()) - upper_bound(b[i].begin(), b[i].end(), a[i][j]);
//                int lesscol = lower_bound(c[j].begin(), c[j].end(), a[i][j]) - c[j].begin();
//                int morecol = (c[j].end()) - upper_bound(c[j].begin(), c[j].end(), a[i][j]);

//            cerr << i << " " << j << " " << lessrow << " " << morerow << " " << lesscol << " " << morecol << endl;
            ans[i][j] = max(lesscol, lessrow) + max(morecol, morerow);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] + 1 << " \n"[j == m - 1];
        }
    }
    return 0;
}
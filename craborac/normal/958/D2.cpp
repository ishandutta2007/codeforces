#include <bits/stdc++.h>

using namespace std;

const double eps = (double)1e-7;

bool cmp(pair<vector<double>, int> a, pair<vector<double>, int> b)
{
    auto q = a.first;
    auto w = b.first;
    if (q.size() != w.size())
        return q.size() < w.size();
    for (int i = 0; i < (int)q.size(); i++)
    {
        if (abs(q[i] - w[i]) > eps)
            return q[i] < w[i];
    }
    return a.second < b.second;
}

bool cmp2(vector<double> q, vector<double> w)
{
    if (q.size() != w.size())
        return false;
    for (int i = 0; i < (int)q.size(); i++)
    {
        if (abs(q[i] - w[i]) > eps)
            return false;
    }
    return true;
}

vector<vector<double> > mas[(int)1e5 + 10];
pair<vector<double>, int> arr[(int)1e5 + 10];
int used[(int)1e5 + 10], ans[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int q = 0; q < k; q++)
        {
            vector<double> w;
            w.clear();
            for (int j = 0; j < m; j++)
            {
                double c;
                cin >> c;
                w.push_back(c);
            }
            mas[i].push_back(w);
        }
        int cnt = 0;
        for (int q = 0; q < m; q++)
        {
            bool d = 0;
            for (int j = cnt; j < k; j++)
            {
                if (abs(mas[i][j][q]) > eps)
                {
                    d = 1;
                    swap(mas[i][j], mas[i][cnt]);
                    break;
                }
            }
            if (d)
            {
                double a = mas[i][cnt][q];
                for (int j = 0; j < m; j++)
                {
                    mas[i][cnt][j] /= a;
                }
                for (int j = 0; j < k; j++)
                {
                    if (j != cnt)
                    {
                        a = mas[i][j][q] / mas[i][cnt][q];
                        for (int w = 0; w < m; w++)
                        {
                            mas[i][j][w] -= a * mas[i][cnt][w];
                        }
                    }
                }
                cnt++;
            }
        }
        arr[i].first.clear();
        arr[i].second = i;
        for (int j = 0; j < cnt; j++)
        {
            for (int q = 0; q < m; q++)
            {
                arr[i].first.push_back(mas[i][j][q]);
            }
        }
    }
    sort(arr, arr + n, cmp);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || !cmp2(arr[i].first, arr[i - 1].first))
            cnt++;
        used[arr[i].second] = cnt - 1;
    }
    fill(ans, ans + cnt, -1);
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ans[used[i]] == -1)
        {
            cnt++;
            ans[used[i]] = cnt;
        }
        cout << ans[used[i]] << " ";
    }
    cout << endl;
    return 0;
}
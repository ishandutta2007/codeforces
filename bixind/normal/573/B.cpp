#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, i;
    cin >> n;
    vector<int> hght(n);
    vector< pair<int, int> > srt(n);
    vector<bool> used(n, false);
    for (i = 0; i < n; i++)
    {
        cin >> hght[i];
        srt[i] = make_pair(hght[i], i);
    }
    sort(srt.begin(), srt.end());
    vector<int> dl, dln;
    dl.push_back(0);
    dl.push_back(n - 1);
    int cnt = 0;
    int v, pos = 0;
    for (i = 0; i < n; i++)
    {
        if (cnt >= n) break;
        dln.clear();
        for (int j = 0; j < dl.size(); j++)
        {
            if (!used[dl[j]])
            {
                cnt++;
                v = dl[j];
                used[dl[j]] = true;
                if (v > 0 && !used[v - 1])
                {
                    dln.push_back(v - 1);
                }
                if (v < n - 1 && !used[v + 1])
                {
                    dln.push_back(v + 1);
                }
            }
        }
        while (pos < n && srt[pos].first <= i + 1)
        {
            v = srt[pos].second;
            if (!used[v])
            {
                cnt++;
                v = v;
                used[v] = true;
                if (v > 0 && !used[v - 1])
                {
                    dln.push_back(v - 1);
                }
                if (v < n - 1 && !used[v + 1])
                {
                    dln.push_back(v + 1);
                }
            }
            pos++;
        }
        swap(dln, dl);
    }
    cout << i << endl;
    return 0;
}
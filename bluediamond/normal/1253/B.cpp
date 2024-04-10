#include <bits/stdc++.h>
 
using namespace std;
 
const int N = (int) 1e6 + 7;
int n;
int a[N];
bool act[N];
bool seen[N];
int cnt_act;
 
void upd(int i)
{
    int x = abs(a[i]);
    if (a[i] > 0)
    {
        cnt_act++;
        if (seen[x])
        {
            cout << "-1\n";
            exit(0);
        }
        act[x] = seen[x] = 1;
    }
    else
    {
        cnt_act--;
        if (act[x] == 0)
        {
            cout << "-1\n";
            exit(0);
        }
        act[x] = 0;
    }
}
 
bool fini()
{
    return (cnt_act == 0);
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans;
    int i = 1;
    while (i <= n)
    {
        int j = i;
        upd(i);
        j++;
        while (1)
        {
            if (fini())
            {
                break;
            }
            if (j > n)
            {
                cout << "-1\n";
                return 0;
            }
            upd(j);
            j++;
        }
        ans.push_back(j - i);
        cnt_act = 0;
        for (int k = i; k < j; k++)
        {
            act[abs(a[k])] = seen[abs(a[k])] = 0;
        }
        i = j;
    }
 
    cout << (int) ans.size() << "\n";
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
 
}
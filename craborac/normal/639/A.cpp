#include <bits/stdc++.h>

using namespace std;

int a[(int)2e5 + 10];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    int n, k, q;
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sp;
    for (int qwe = 0; qwe < q; qwe++)
    {
        int t, d;
        cin >> t >> d;
        d--;
        if (t == 1)
        {
            if (sp.size() <= k)
            {
                sp.push_back(a[d]);
                for (int i = sp.size() - 1; i > 0; i--)
                {
                    if (sp[i] > sp[i - 1])
                        swap(sp[i], sp[i - 1]);
                    else
                        break;
                }
            }
            else
            {
                sp[k] = a[d];
                for (int i = sp.size() - 1; i > 0; i--)
                {
                    if (sp[i] > sp[i - 1])
                        swap(sp[i], sp[i - 1]);
                    else
                        break;
                }
            }
        }
        else
        {
            bool t = 0;
            for (int i = 0; i < min(k, (int)sp.size()); i++)
                if (sp[i] == a[d])
                    t = 1;
            if (t)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        /*
        for (int i = 0; i < sp.size(); i++)
            cout << sp[i] << " ";
        cout << endl;
        */
    }
    return 0;
}
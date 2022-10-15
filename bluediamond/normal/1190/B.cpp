#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0); cout.tie(0);

        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++)
                cin >> a[i];
        sort(a.begin(), a.end());
        int matchy = 0, id;
        for (int i = 1; i < n; i++)
                matchy += (a[i] == a[i - 1]);
        if (matchy >= 2)
        {
                cout << "cslnb\n";
                return 0;
        }
        if (matchy == 1)
        {
                for (int i = 1; i < n; i++)
                        if (a[i] == a[i - 1])
                                id = i - 1;
                if (a[id] == 0)
                {
                        cout << "cslnb\n";
                        return 0;
                }
                if (id - 1 >= 0 && a[id] - 1 == a[id - 1])
                {
                        cout << "cslnb\n";
                        return 0;
                }
        }
        int sol = 0;
        for (int i = 0; i < n; i++)
        {
                sol += a[i] - i;
                sol %= 2;
        }
        if (sol)
                cout << "sjfnb\n";
        else
                cout << "cslnb\n";
        return 0;
}
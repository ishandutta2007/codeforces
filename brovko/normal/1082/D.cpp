#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[505], k, s, used[505];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        if(a[i]>1)
            {
                k++;
                v.push_back(i);
                used[i]++;
            }
        s+=a[i];
    }
    if(s<2*n-2)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES " << min(n, k+2)-1 << "\n";
    cout << n-1 << "\n";

    for(int i=1;i<v.size();i++)
    {
        cout << v[i]+1 << ' ' << v[i-1]+1 << "\n";
        a[v[i]]--;
        a[v[i-1]]--;
    }

    int L=0;
    int f=0;

    for(int i=0;i<n;i++)
        if(used[i]==0)
        {

            if(f==0)
        {
            f=1;
            used[i]=1;
            a[v[(int)v.size()-1]]--;
            cout << i+1 << ' ' << v[(int)v.size()-1]+1 << "\n";
        }
        else
            {
                while(L<v.size() && a[v[L]]==0)
                    L++;
                if(L==v.size())
                {
                    cout << "NO";
                    return 0;
                }
                a[v[L]]--;
                used[i]++;
                a[i]--;
                cout << i+1 << ' ' << v[L]+1 << "\n";
            }
        }
}
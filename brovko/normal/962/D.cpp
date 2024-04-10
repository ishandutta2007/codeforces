#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 doijwfojeoif

using namespace std;

int n, a[150005];
map <int, int> m;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
        while(m[a[i]]==2)
        {
            m[a[i]]=0;
            a[i]*=2;
            m[a[i]]++;
        }
    }

    for(int i=n-1;i>=0;i--)
        {
            if(m[a[i]])
                {
                    m[a[i]]=0;
                    v.push_back(a[i]);
                }
        }

    cout << v.size() << endl;
    for(int i=0;i<(int)v.size();i++)
        cout << v[(int)v.size()-i-1] << ' ';
}
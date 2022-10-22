#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[200002];
int U[200002];
int ok[200002], ok2[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v1, v2;
        for(int i=0;i<=n;i++) U[i] = ok[i] = ok2[i] = 0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(U[a[i]]) v1.push_back(i);
            U[a[i]] = 1;
        }

        for(int i=1;i<=n;i++)
        {
            if(!U[i]) v2.push_back(i);
        }

        int m = v1.size();
        if(m == 0)
        {
            cout << n << "\n";
            for(int i=1;i<=n;i++) cout << a[i] << " ";
            cout << "\n";
            continue;
        }
        bool flag = true;
        for(int i=0;i<m;i++)
        {
            if(v1[i] != v2[i]) flag = false;
        }
        if(flag)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i] == a[v1[0]])
                {
                    v1[0] = i;
                    break;
                }
            }
        }
        for(int i=0,j=0;;)
        {
            if(i == m || j == m) break;
            if(v1[i] == v2[j])
            {
                a[v1[(i+1)%m]] = v2[j];
                ok[(i+1)%m] = ok2[j] = 1;
                i++; j++;
            }
            else if(v1[i] < v2[j]) i++;
            else if(v1[i] > v2[j]) j++;
        }

        for(int i=0,j=0;;)
        {
            while(i < m && ok[i]) i++;
            while(j < m && ok2[j]) j++;
            if(i == m || j == m) break;
            a[v1[i]] = v2[j];
            ok[i] = ok2[j] = 1;
        }

        cout << n - m << "\n";
        for(int i=1;i<=n;i++) cout << a[i] << " ";
        cout << "\n";
    }
}
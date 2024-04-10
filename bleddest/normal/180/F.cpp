#include<bits/stdc++.h>

using namespace std;

vector<int> p;
int ans = 0;

void rec(int n)
{
    if(p.size() == n)
    {
        for(auto x : p)
            cout << x << " ";
        cout << endl;
        ans++;    
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            bool good = true;
            for(auto x : p)
                if(i == x)
                    good = false;
            if(good)
            {
                p.push_back(i);
                rec(n);
                p.pop_back();
            }
        }
    }
}

vector<int> inverse_permutation(vector<int> p)
{
    int n = p.size();
    vector<int> q(n);
    for(int i = 0; i < n; i++)
        q[p[i]] = i;
    return q;
}

vector<int> mul(vector<int> a, vector<int> b)
{
    int n = a.size();
    vector<int> p(n);
    for(int i = 0; i < n; i++)
        p[i] = a[b[i]];
    return p;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    vector<int> b(n);
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
    }
    vector<int> c = mul(inverse_permutation(a), b);
    for(auto x : c)
        cout << x + 1 << " ";
}
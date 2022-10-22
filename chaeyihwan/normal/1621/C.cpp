#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loop")

using namespace std;
typedef long long ll;

bool u[10002];
int p[10002];

int ask(int i)
{
    cout << "? " << i << endl;
    int k; cin >> k;
    return k;
}

void answer(int n)
{
    cout << "! ";
    for(int i=1;i<=n;i++) cout << p[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        for(int i=1;i<=n;i++) u[i] = false;

        for(int i=1;i<=n;i++)
        {
            if(u[i]) continue;
            bool x = false;
            vector<int> a, b;
            int f = ask(i);
            u[f] = true;
            if(f == i) x = true;
            if(x) b.push_back(f);
            else a.push_back(f);

            while(true)
            {
                int t = ask(i);
                u[t] = true;
                if(t == i) x = true;
                if(t == f) break;
                if(x) b.push_back(t);
                else a.push_back(t);
            }

            for(int j=0;j<a.size();j++) b.push_back(a[j]);

            int m = b.size();
            p[b[m-1]] = b[0];
            for(int i=0;i<m-1;i++)
            {
                p[b[i]] = b[i+1];
            }
        }
        answer(n);
    }
}
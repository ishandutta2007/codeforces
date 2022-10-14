    #include <bits/stdc++.h>
    using namespace std;
    const int N = 100005;
    int n,kk,f[N],sz[N];//Devinw AK IOI!
    int getf(int v) {if (f[v] != v) f[v] = getf(f[v]);return f[v];}
    int main ()
    {
        ios::sync_with_stdio(false);
        cin >> n >> kk;
        int t1,t2;
        for (int i = 1;i <= n;i++) f[i] = i;
        for (int i = 1;i <= kk;i++)
        {
            cin >> t1 >> t2;
            f[getf(t1)] = getf(t2);
        }
        int cnt = 0;
        for (int i = 1;i <= n;i++) if (f[i] == i) ++cnt;
        cout << kk - (n - cnt);
        return 0;
    }
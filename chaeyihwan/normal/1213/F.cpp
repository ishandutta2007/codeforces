#include <bits/stdc++.h>

using namespace std;

int n, k, p[200002], q[200002], invp[200002], invq[200002], chk[200002];
char s[200002];

int main()
{
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) cin >> q[i];

    for(int i=1;i<=n;i++) invp[p[i]] = i, invq[q[i]] = i;
    int pre = 1, now = 0;
    int j=1;
    for(int i=1;i<=n;i++)
    {
        chk[invq[p[i]]] = 1;
        while(chk[j]) j++;
        if(j > i)
        {
            for(;pre<=i;pre++)
                s[p[pre]] = now + 'a';
            now++;
        }

        if(now == k)
        {
            for(;pre<=n;pre++)
                if(s[p[pre]] == 0) s[p[pre]] = now + 'a' - 1;
            break;
        }
    }

    if(now < k) cout << "NO\n";
    else
    {
        cout << "YES\n";
        for(int i=1;i<=n;i++) cout << s[i];
    }
}
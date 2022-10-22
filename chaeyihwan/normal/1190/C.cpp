#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void gameend(int n)
{
    if(n == 0) cout << "once again";
    if(n == 1) cout << "tokitsukaze";
    if(n == 2) cout << "quailty";

    exit(0);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int pre = s[0] - '0', suf = s[n-1] - '0', prel = 0, sufl = 0;

    for(int i=0;i<n;i++)
    {
        if(s[i] - '0' != pre) break;
        prel++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i] - '0' != suf) break;
        sufl++;
    }

    int L = n - prel - sufl;
    int a = max(prel, sufl), b = min(prel, sufl);
    if(pre == suf && L <= k) gameend(1);
    if(pre != suf && L + b <= k) gameend(1);

    if(pre == suf) gameend(0);
    if(a >= k || k <= L- 1) gameend(0);
    if(k <= L + a - 2) gameend(0);
    gameend(2);
}
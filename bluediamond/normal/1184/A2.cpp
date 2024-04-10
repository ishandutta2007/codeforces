#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b)
{
        if (b == 0)
                return a;
        else
                return gcd(b, a % b);
}

const int N = (int) 2e5 + 7;
bool good[N];
int cnt[N];
int value[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int n;
        cin >> n;
        string s;
        cin >> s;

        int res = 0;
        /// k == 0 => s needs to contain only 0
        bool all0 = 1;
        for (auto &x : s)
                if (x == '1')
                        all0 = 0;
        if (all0)
                res++;
        for (int jump = 1; jump < n; jump++)
                cnt[gcd(jump, n)]++;

        for (int jump = 1; jump < n; jump++)
                if (n % jump == 0)
                {
                        for (int j = 0; j < jump; j++)
                                value[j] = 0;
                        for (int j = 0; j < n; j++)
                                if (s[j] == '1')
                                        value[j % jump] ^= 1;
                        bool all_0 = 1;
                        for (int j = 0; j < jump; j++)
                                if (value[j])
                                        all_0 = 0;
                        good[jump] = all_0;
                }
        for (int jump = 1; jump < n; jump++)
                if (good[jump])
                        res += cnt[jump];
        cout << res << "\n";
        return 0;
}
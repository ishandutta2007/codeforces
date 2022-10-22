#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;
int ka[5005], kb[5005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.size();

    for(int i = 0; i < n; i++)
    {
        ka[i + 1] = ka[i];
        if(s[i] == 'a')
            ka[i + 1]++;

        kb[i + 1] = kb[i];
        if(s[i] == 'b')
            kb[i + 1]++;
    }

    int Max = 0;

    for(int i = 0; i < n; i++)
        for(int j = i; j <= n; j++)
            Max = max(Max, ka[n] - ka[j] + ka[i] + kb[j] - kb[i]);
    cout << Max;
}
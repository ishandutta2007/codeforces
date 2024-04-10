/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 1002;

int n;

ll pref[N_MAX];

int answer[N_MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        cout << "? 1 " << i << endl;
        cin >> pref[i];
    }
    for(int i = 3; i <= n; i++)
        answer[i] = pref[i] - pref[i - 1];
    ll aux;
    cout << "? 2 3" << endl;
    cin >> aux;
    answer[1] = pref[3] - aux;
    answer[2] = pref[2] - answer[1];
    cout << "! ";
    for(int i = 1; i <= n; i++)
        cout << answer[i] << " ";
    cout << endl;
    return 0;
}
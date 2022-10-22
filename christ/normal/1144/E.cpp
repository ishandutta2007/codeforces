#include <bits/stdc++.h>

using namespace std;

vector<int> arr(200005);

int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int k;
    cin>>k;
    string s, t;
    cin>>s>>t;
    for (int x = 0; x < k; x++)
        arr[x] = s[x] + t[x] - 2 * 'a';
    for (int x = k-1; x > 0; x--)
        arr[x-1] += arr[x] / 26, arr[x] %= 26;
    for (int x = 0; x < k; x++)
    {
        if (x < k-1)
            arr[x+1] += arr[x] % 2 * 26;
        arr[x] /= 2;
    }
    for (int x = 0; x < k; x++)
        printf("%c", arr[x] + 'a');
}
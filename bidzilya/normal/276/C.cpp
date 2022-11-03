#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

const int N = 222222;

int a[N],b[N];
int n,q;
int dx[N];

int main()
{
    cin >> n >> q;
    for (int i=0; i<n; i++)
        cin >> a[i];
    sort(a, a+n);
    for (int i=0; i<q; i++)
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        dx[l]++;
        dx[r+1]--;
    }
    int sum = 0;
    for (int i=0; i<n; i++)
    {
        sum += dx[i];
        b[i] = sum;
    }
    sort(b, b+n);
    long long ans = 0;
    for (int i=0; i<n; i++)
        ans += 1LL*b[i]*a[i];
    cout << ans << endl;

    return 0;
}
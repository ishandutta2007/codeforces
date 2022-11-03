#include <iostream>
#include <map>
using namespace std;

map<int,long long> a;

int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        int y = 0;
        while (x > 0)
        {
            y += x%2;
            x /= 2;
        }
        ans += a[y];
        a[y]++;
    }
    cout << ans << endl;

    return 0;
}
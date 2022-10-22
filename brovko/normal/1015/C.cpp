#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long n, m, a[100000], b[100000], s, k;
vector <int> c;

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> a[i] >> b[i];
    s=0;
    for(int i=0;i<n;i++)
        s=s+b[i];
    if(s>m)
    {
        cout << -1;
        return 0;
    }
    s=0;
    for(int i=0;i<n;i++)
        s=s+a[i];
    for(int i=0;i<n;i++)
        c.push_back(a[i]-b[i]);
    sort(c.begin(), c.end());
    while(s>m)
    {
        n--;
        k++;
        s=s-c[n];
    }
    cout << k;
    return 0;
}
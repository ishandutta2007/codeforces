#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, c;
vector <int> a;

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(), a.end());
    if(a[0]==1 && k==0)
    {
        cout << -1;
        return 0;
    }
    if(k==0)
    {
        cout << 1;
        return 0;
    }
    if(k==n)
    {
        cout << 1000000000;
        return 0;
    }
    if(a[k-1]==a[k])
        cout << -1;
    else cout << a[k-1];
    return 0;
}
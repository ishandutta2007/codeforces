#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c;
long long Min;
vector <int> a;
int main()
{
    cin >> n;
    for(int i=0;i<2*n;i++)
    {
        cin >> c;
        a.push_back(c);
    }
    sort(a.begin(), a.end());
    Min=(long long)(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    for(int i=1;i<n;i++)
    {
        Min=min(Min, (long long)(a[2*n-1]-a[0])*(a[i+n-1]-a[i]));
    }
    cout << Min;
    return 0;
}
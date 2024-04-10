#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, k, c;
vector <int> a;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        {
            cin >> c;
            a.push_back(c);
        }
    sort(a.begin(), a.end());
    for(int i=1;i<n;i++)
        if(a[i]>a[k])
        k++;
    cout << k;
    return 0;
}
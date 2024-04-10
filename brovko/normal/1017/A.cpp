#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, a1, a2, a3, a4, s;
vector <int> a;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a1 >> a2 >> a3 >> a4;
        a.push_back(a1+a2+a3+a4);
    }
    s=a[0];
    sort(a.begin(), a.end());
    int i=n-1;
    int j=1;
    while(a[i]>s)
    {
        i--;
        j++;
    }
    cout << j;
    return 0;
}
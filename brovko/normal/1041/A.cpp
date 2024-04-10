#include <iostream>

using namespace std;
int n, a[1000], Min, Max, f;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    Min=a[0];
    Max=a[0];
    for(int i=1;i<n;i++)
    {
        Min=min(Min, a[i]);
        Max=max(Max, a[i]);
    }
    cout << Max-Min-n+1;
    return 0;
}
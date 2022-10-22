#include <iostream>

using namespace std;
int n, a[200000], k, Max;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    Max=1;
    k=1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i+1]>a[i]*2)
        {
            Max=max(Max, k);
            k=1;
        }
        else k++;
    }
    Max=max(Max, k);
    cout << Max;
    return 0;
}
#include <iostream>

using namespace std;
int n, a[1000], used[1000], p;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<1000;j++)
            used[j]=0;
        p=i;
        used[p]++;
        while(used[p]<2)
        {
            p=a[p]-1;
            used[p]++;
        }
        cout << p+1 << ' ';
    }
    return 0;
}
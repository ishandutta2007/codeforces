#include <iostream>

using namespace std;
int n, a[10], Min;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    if(n==1)
    {
        cout << -1;
        return 0;
    }
    if(n==2 && a[0]==a[1])
    {
        cout << -1;
        return 0;
    }
    Min=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<a[Min])
            Min=i;
    }
    cout << 1 << endl;
    cout << Min+1;
    return 0;
}
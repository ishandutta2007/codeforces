#include <iostream>
using namespace std;

int main()
{
    int n,sum = 0, ans = 0;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
    }
    for (int i=1; i<=5; i++)
        if ((sum+i-1)%(n+1)!=0)
            ans++;
    cout << ans << endl;
    return 0;
}
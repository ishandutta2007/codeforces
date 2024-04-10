#include <iostream>
using namespace std;
int f(int d,int x)
{
    if(x < 0) return 0;
    if(x == 0) return 1;
    return x/d + 1;
}
int main()
{
    int n,d;
    cin >> n >> d;
    int a[n];
    int cnt = 0,tmp;
    cin >> a[0];
    for(int k = 1 ; k < n; k ++)
    {
        cin >> a[k];
        tmp = f(d,a[k-1] - a[k]);
        a[k] += d * tmp;
        cnt += tmp;
    }
    cout << cnt << endl;
    return 0;
}
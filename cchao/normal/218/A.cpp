#include <iostream>
using namespace std;
int main()
{
    int n,q;
    while(cin >> n >> q)
    {
        int a[2*n + 1];
        int m = -1,c = 0;
        for(int k = 0; k < 2*n + 1; k++)
        {
            cin >> a[k];
            if(a[k] > m)
            {
                m = a[k];
                c = 1;
            }
            else if(a[k]==m)
            {
                c++;
            }
        }
        //int f = 0;
        for(int k = 0 ; k < 2*n + 1; k++)
        {
            if(q > 0 && k % 2 == 1 && a[k] - 1 > a[k-1]  && a[k] - 1 > a[k+1])
            {
                q--;
                a[k]--;
            }
            cout << a[k] << ' ';
        }
        cout << endl;
    }
    return 0;
}
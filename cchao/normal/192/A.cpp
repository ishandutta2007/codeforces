#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i=0,j;
    int ans = 0;
    for(int k=1;i<= n/2 ;k++)
    {
        i += k;
        j = i;
        for(int kk = k+1; i + j < n;kk++)
        {
            j += kk;
        }
        if(i+j == n)
        {
            //cout << i << ' ' << j << endl;
            ans = 1;
            break;
        }
        if(ans == 1) break;
    }
    if(ans == 1) cout << "YES";
    else cout << "NO";
    return 0;
}
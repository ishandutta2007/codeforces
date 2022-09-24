#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
long long n , m;
vector < vector<long long> > d;


void calc (int x = 0, int y = 0, int mask = 0, int next_mask = 0)
{
    }


int main()
{
    cin >> n >> m;
   
    
    if (m > n - 1)
    {
        cout << n;
        return 0;
    }
    else
    {
        n -= m;
        long long l = 0;
        long long r = 1e10;
        long long mid = 0;
        while (l < r)
        {
            mid = (l + r + 1) / 2;
            if ( ( ( 1 + mid) * mid)  < 2 * n) l = mid;
            else r = mid - 1;
        } 
        cout <<(long long) (l + 1 + m);
    }
}
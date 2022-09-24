#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x;
    cin >> x;
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= x; j++)
        {
           if(i % j == 0 && i * j > x && i < x * j)
           {
               cout << i << " " << j << "\n";
               return 0;
           }
        }
    }
    cout << -1 << "\n";
    return 0;
}
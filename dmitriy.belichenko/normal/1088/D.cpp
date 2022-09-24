#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
int ask(int a , int b)
{
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int p = ask(0 , 0);
    int a = 0 , b = 0;
    for(int i = 0; i < 30; i++)
    {
        int z = 30 - i - 1;
        z = 1 << z;
        int x = ask(a|z , b);
        int y = ask(a , b|z);
        if(x == y)
        {
            if(p == 1)
            {
                a |= z;
            }
            else
            {
                b |= z;
            }
            p = x;
        }
        else
        {
            if(x == -1)
            {
                a |= z;
                b |= z;
            }
        }
    }
    cout << "! " << a << " " << b << endl;
    return 0;
}
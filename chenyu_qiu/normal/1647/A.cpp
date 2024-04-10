#include<bits/stdc++.h>
#define LL long long
#define D double
#define LD long double
#define S second
#define F first
#define PB push_back
using namespace std;
int main()
{
    int t;
    cin >> t;
    int a ,b;
    for (int i=0; i<t; i++)
    {
        int n;
        cin >> n;
        int type;
        if (n % 3 == 1)
            type = 1;
        else
            type = 2;
        int sum = 0;
        while (sum != n)
        {
            cout << type;
            sum += type;
            type = 3 - type;
        }
        cout << endl;
    }
 
}
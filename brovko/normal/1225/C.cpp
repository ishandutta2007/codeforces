#include <bits/stdc++.h>

using namespace std;
int n, p;
int kc(int x)
{
    if(x==0)
        return 0;
    return kc(x/2)+x%2;
}

int main()
{
    cin >> n >> p;
    for(int i=1;(n>=1 && i<1000);i++)
    {
        n-=p;
        if(n>=i && kc(n)<=i)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
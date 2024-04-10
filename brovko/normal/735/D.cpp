#include <iostream>
#include <cmath>

using namespace std;
int n;
int pr(int i)
{
    for(int j=2;j<=(int)sqrt(i);j++)
        if(i%j==0)
        return 0;
    if(i==1)
        return 0;
    return 1;
}

int main()
{
    cin >> n;
    if(pr(n)==1)
    {
        cout << 1;
        return 0;
    }
    for(int i=2;i<min(n, 10000);i++)
        if(pr(i)==1 && pr(n-i)==1)
    {
        cout << 2;
        return 0;
    }
    cout << 3;
    return 0;
}
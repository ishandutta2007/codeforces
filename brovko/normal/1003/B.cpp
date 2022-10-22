#include <iostream>

using namespace std;
int a, b, x, n, c[200], k, ab;

int main()
{
    cin >> a >> b >> x;
    n=a+b;
    if(a>b)
    {
        c[0]=0;
        a--;
    }
    else
    {
        c[0]=1;
        b--;
    }
    x--;
    k=1;
    for(int i=x;i>0;i--)
    {
        c[k]=1-c[k-1];
        k++;
        if(c[k-1]==1)
            b--;
        else a--;
    }
    for(int i=0;i<k;i++)
        cout << c[i];
    if(c[k-1]==0)
    {
        for(int i=0;i<a;i++)
            cout << 0;
        for(int i=0;i<b;i++)
            cout << 1;
    }
    else
    {
        for(int i=0;i<b;i++)
            cout << 1;
        for(int i=0;i<a;i++)
            cout << 0;
    }
    return 0;
}
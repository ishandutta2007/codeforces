#include <iostream>

using namespace std;
int n, x, a[100000], b[100001], c[100000], d[100001];

int an(int i, int j)
{
    int c[20];
    for(int l=0;l<20;l++)
    {
        c[l]=(i%2)*(j%2);
        i=i/2;
        j=j/2;
    }
    int r=0;
    for(int l=19;l>=0;l--)
    {
        r=r*2+c[l];
    }
    return r;
}

int main()
{
    cin >> n >> x;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        c[i]=an(a[i], x);
        b[a[i]]++;
        d[c[i]]++;
    }
    for(int i=0;i<n;i++)
        if(b[a[i]]>=2)
    {
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        if(c[i]!=a[i] && b[c[i]]==1)
        {
            cout << 1;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        if(d[c[i]]>=2)
    {
        cout << 2;
        return 0;
    }
    cout << -1;
    return 0;
}
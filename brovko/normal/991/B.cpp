#include <iostream>

using namespace std;
int n, a[100], b[6], s, i, k;
int ab(int d)
{
    if(d>0)
        return d;
    else return -d;
}

int main()
{
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        b[a[i]]++;
        s=s+a[i];
    }
    while(ab(4*n-s)<ab(5*n-s))
    {
        i=2;
        while(b[i]==0)
            i++;
        b[i]--;
        s=s+5-i;
        k++;
    }
    cout << k;
    return 0;
}
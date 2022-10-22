#include <iostream>

using namespace std;
int n, a[200], k, j, t;

int main()
{
    k=0;
    cin >> n;
    for(int i=0;i<2*n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
    {
        j=0;
        while(a[j]==0)
            j++;
        t=j+1;
        while(a[t]!=a[j])
        {
            if(a[t]!=0)
                k++;
            t++;
        }
        a[j]=0;
        a[t]=0;
    }
    cout << k;
    return 0;
}
#include <iostream>

using namespace std;
long long n, a[100000], b[100000], k1, k00, k01, k10;
char c;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        a[i]=(int)c-(int)'0';
    }
    for(int i=0;i<n;i++)
    {
        cin >> c;
        b[i]=(int)c-(int)'0';
    }
    for(int i=0;i<n;i++)
    {
        k1=k1+a[i];
        if(a[i]==0 && b[i]==0)
            k00++;
        if(a[i]==0 && b[i]==1)
            k01++;
        if(a[i]==1 && b[i]==0)
            k10++;
    }
    cout << (long long)k00*k1+k01*k10;
    return 0;
}
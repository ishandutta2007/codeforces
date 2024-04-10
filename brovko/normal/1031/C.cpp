#include <iostream>

using namespace std;
long long a, b, b1, s, p, t, n, m, kn[1000000];

int main()
{
    cin >> a >> b;
    b1=b;
    p=0;
    s=0;
    while(s<=a+b)
    {
        p++;
        s+=p;
    }
    p--;
    t=p;
    while(b>0 && t>0)
    {
        if(b>t)
        {
            b-=t;
            kn[t]++;
            t--;
            n++;
        }
        else
        {
            kn[b]++;
            b=0;
            t--;
            n++;
        }
    }
    cout << p-n << endl;
    for(int i=1;i<=p;i++)
        if(kn[i]==0)
        cout << i << ' ';
    cout << endl;
    cout << n << endl;
    for(int i=1;i<=p;i++)
        if(kn[i]>0)
        cout << i << ' ';
    cout << endl;
    return 0;
}
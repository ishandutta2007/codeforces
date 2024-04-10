#include <bits/stdc++.h>

using namespace std;
long long st,dr;
long long prefix(long long x)
{
    long long ans=0;
    long long val=1,aux;
    while(val<=x)
    {
        aux=val;
        while(aux<=x)
        {
            ans++;
            aux*=3;
        }
        val*=2;
    }
    return ans;
}
int main()
{///
    cin>>st>>dr;
    cout<<prefix(dr)-prefix(st-1);
    return 0;
}
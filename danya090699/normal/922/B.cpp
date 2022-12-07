#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, an=0;
    cin>>n;
    for(int a=1; a<=n; a++)
    {
        for(int b=a; b<=n; b++)
        {
            int c=(a^b);
            if(c<=n and c>=b and a+b>c) an++;
        }
    }
    cout<<an;
}
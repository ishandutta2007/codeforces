#include <bits/stdc++.h>

using namespace std;

int n,ap[605],S,x;

int main()
{
    cin>>n;
    while(n--)
    {
        cin>>x;
        ap[x]=1;
    }
    for(int i=1;i<=600;i++)
        S+=ap[i];
    cout<<S;
    return 0;
}
/**


**/
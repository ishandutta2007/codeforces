#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x;
    cin>>x;
    for(int a=1; a>0; a*=10)
    {
        if(x/a<10)
        {
            cout<<(x/a+1)*a-x;
            break;
        }
    }
}
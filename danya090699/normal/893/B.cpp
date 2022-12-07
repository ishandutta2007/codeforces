#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int a=10; ; a--)
    {
        int x=((1<<a)-1)*(1<<(a-1));
        if(n%x==0)
        {
            cout<<x;
            break;
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, add=1, an=0;
    cin>>a>>b;
    if(a>b) swap(a, b);
    while(a<b)
    {
        if(b-a==1)
        {
            an+=add;
            break;
        }
        a++, b--, an+=add*2, add++;
    }
    cout<<an;
}
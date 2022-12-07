#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, a=1;
    cin>>x>>y;
    while(x>=0 and y>=0)
    {
        if(a%2==1) x-=a;
        else y-=a;
        a++;
    }
    if(a%2==1) cout<<"Valera";
    else cout<<"Vladik";
}
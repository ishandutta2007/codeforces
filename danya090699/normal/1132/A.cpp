#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int q1, q2, q3, q4;
    cin>>q1>>q2>>q3>>q4;
    if(q1==q4)
    {
        if(q3)
        {
            if(q1==0) cout<<0;
            else cout<<1;
        }
        else cout<<1;
    }
    else cout<<0;
}
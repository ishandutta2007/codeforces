#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, su=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        su+=ar[a];
    }
    int q=0;
    for(int a=0; a<n; a++)
    {
        q+=ar[a];
        if(q*2>=su)
        {
            cout<<a+1;
            break;
        }
    }
}
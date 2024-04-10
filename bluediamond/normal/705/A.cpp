#include <bits/stdc++.h>

using namespace std;
int n;
int main()
{
    cin>>n;
    cout<<"I ";
    for(int i=1;i<n;i++)
    {
        if(i%2==1)
            cout<<"hate that I ";
        else
            cout<<"love that I ";
    }
    if(n%2==1)
        cout<<"hate it";
    else
        cout<<"love it";
    return 0;
}
/**

**/
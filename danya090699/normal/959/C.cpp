#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=5) cout<<"-1\n";
    else
    {
        cout<<"1 2\n";
        cout<<"2 3\n";
        cout<<"3 4\n";
        cout<<"3 5\n";
        for(int a=6; a<=n; a++) cout<<"2 "<<a<<"\n";
    }
    for(int a=2; a<=n; a++) cout<<a-1<<" "<<a<<"\n";
}
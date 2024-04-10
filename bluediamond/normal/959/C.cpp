#include <iostream>

using namespace std;

int n;

int main()
{
    cin>>n;
    if(n<=5)
        cout<<"-1\n";
    else
    {
        cout<<"1 2\n";
        cout<<"1 3\n";
        cout<<"1 4\n";
        for(int i=5;i<=n;i++)
            cout<<"4 "<<i<<"\n";
    }
    for(int i=1;i<n;i++)
        cout<<i<<" "<<i+1<<"\n";
    return 0;
}
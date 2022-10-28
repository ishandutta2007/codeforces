#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;
    cin>>n;
    if(n%2!=0)
    {
        cout<<-1;return 0;
    }
    for(int i=1;i<n;i+=2)
    {
        cout<<i+1<<" "<<i<<" ";
    }
    return 0; 
}
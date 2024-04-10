#include<bits/stdc++.h>
using namespace std;
int main()
{
    int y,b,r;
    cin>>y>>b>>r;
    b--;r-=2;
    cout<<min(b,min(y,r))*3+3<<endl;
}
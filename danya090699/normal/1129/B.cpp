#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int k, q=1999;
    cin>>k;
    int y=((k/q+1)*q)-k, x=k/q+1+y;
    cout<<q+1<<"\n";
    for(int a=0; a<q-1; a++) cout<<"0 ";
    cout<<-y<<" "<<x;
}
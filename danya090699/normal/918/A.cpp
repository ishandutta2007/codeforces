#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, pr1=1, pr2=1;
    cin>>n;
    char an[n+1];
    for(int a=1; a<=n; a++) an[a]='o';
    an[1]='O';
    while(1)
    {
        int x=pr1+pr2;
        if(x>n) break;
        an[x]='O';
        pr1=x;
        swap(pr1, pr2);
    }
    for(int a=1; a<=n; a++) cout<<an[a];
}
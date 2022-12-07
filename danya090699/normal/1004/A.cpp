#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d;
    cin>>n>>d;
    int ar[n], an=2;
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a+1<n; a++)
    {
        if(ar[a+1]-ar[a]>2*d) an+=2;
        else if(ar[a+1]-ar[a]==2*d) an++;
    }
    cout<<an;
}
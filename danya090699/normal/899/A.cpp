#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1=0, q2=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(x==1) q1++;
        else q2++;
    }
    q2=min(q2, q1);
    cout<<q2+(q1-q2)/3;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], q1=0, q2=0, an=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        if(ar[a]==1) q1++;
        else q2++;
    }
    for(int a=0; a<k; a++)
    {
        for(int b=a; b<n; b+=k)
        {
            if(ar[b]==1) q1--;
            else q2--;
        }
        an=max(an, abs(q1-q2));
        for(int b=a; b<n; b+=k)
        {
            if(ar[b]==1) q1++;
            else q2++;
        }
    }
    cout<<an;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1=0, q2=0;
    cin>>n;
    int ar[n/2];
    for(int a=0; a<n/2; a++) cin>>ar[a];
    sort(ar, ar+n/2);
    for(int a=0; a<n/2; a++)
    {
        int p=ar[a];
        p--;
        q1+=abs(p-(a*2)), q2+=abs(p-(a*2+1));
    }
    cout<<min(q1, q2);
}
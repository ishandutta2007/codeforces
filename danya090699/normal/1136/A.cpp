#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n][2];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a][0]>>ar[a][1];
    }
    int k;
    cin>>k;
    for(int a=0; a<n; a++) if(ar[a][1]>=k) an++;
    cout<<an;
}
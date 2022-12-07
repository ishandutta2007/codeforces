#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int ga[n], mo[m];
    for(int a=0; a<n; a++) cin>>ga[a];
    for(int a=0; a<m; a++) cin>>mo[a];
    int yk=0, an=0;
    for(int a=0; a<n; a++)
    {
        if(yk<m)
        {
            if(mo[yk]>=ga[a])
            {
                an++, yk++;
            }
        }
    }
    cout<<an;
}
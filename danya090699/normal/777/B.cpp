#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0, an1=0, an2=0;
    cin>>n;
    char sh[n], mo[n];
    for(int a=0; a<n; a++) cin>>sh[a];
    for(int a=0; a<n; a++) cin>>mo[a];
    sort(sh, sh+n), sort(mo, mo+n);
    for(int a=0; a<n; a++)
    {
        while(yk<n)
        {
            if(mo[yk]>=sh[a]) break;
            else yk++;
        }
        if(yk==n) an1++;
        else yk++;
    }
    yk=0;
    for(int a=0; a<n; a++)
    {
        while(yk<n)
        {
            if(mo[yk]>sh[a]) break;
            else yk++;
        }
        if(yk!=n)
        {
            an2++, yk++;
        }
    }
    cout<<an1<<"\n"<<an2;
}
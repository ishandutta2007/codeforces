#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int ar[3], an=0;
        for(int a=0; a<3; a++)
        {
            cin>>ar[a];
            if(ar[a]) ar[a]--, an++;
        }
        sort(ar, ar+3);
        if(ar[2] and ar[1]) ar[2]--, ar[1]--, an++;
        if(ar[2] and ar[0]) ar[2]--, ar[0]--, an++;
        if(ar[1] and ar[0]) ar[1]--, ar[0]--, an++;
        if(ar[0] and ar[1] and ar[2]) an++;
        cout<<an<<"\n";
    }
}
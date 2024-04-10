#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        int r=0, s=0, p=0;
        for(int a=0; a<S.size(); a++)
        {
            if(S[a]=='R') p++;
            if(S[a]=='S') r++;
            if(S[a]=='P') s++;
        }
        char sy;
        if(r>=s and r>=p) sy='R';
        else if(s>=r and s>=p) sy='S';
        else sy='P';

        for(int a=0; a<S.size(); a++) cout<<sy;
        cout<<"\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int an[n], ok[n];
    long long su=0;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        bool ot=(s[0]=='-') ? true : false;
        stringstream ss;
        ss<<s;
        int x, os;
        char sy;
        ss>>an[a]>>sy>>os;
        if(os)
        {
            ok[a]=1;
            if(ot) an[a]--, su+=100000-os;
            else su+=os;
        }
        else ok[a]=0;
    }
    su/=100000;
    for(int a=0; a<n; a++)
    {
        if(su and ok[a]) an[a]++, su--;
        cout<<an[a]<<"\n";
    }
}
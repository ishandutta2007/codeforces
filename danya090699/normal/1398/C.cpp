#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n, pref=0;
        cin>>n;
        string s;
        cin>>s;
        map <int, int> ma;
        ma[0]++;
        long long an=0;
        for(int a=0; a<n; a++)
        {
            pref+=(s[a]-'0');
            int x=a+1-pref;
            an+=ma[x];
            ma[x]++;
        }
        cout<<an<<"\n";
    }
}
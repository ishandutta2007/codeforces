#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=5e4+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, q[sz];
        cin>>n;
        for(int a=0; a<sz; a++) q[a]=0;
        for(int i=sz-1; i>=2; i--)
        {
            int cu=i*(i-1)/2;
            while(n>=cu) n-=cu, q[i]++;
        }
        string an="1";
        for(int a=0; a<sz; a++)
        {
            for(int b=0; b<q[a]; b++) an.push_back('7');
            an.push_back('3');
        }
        while(an.back()=='3') an.pop_back();
        cout<<an<<"\n";
    }
}
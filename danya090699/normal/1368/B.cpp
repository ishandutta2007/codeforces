#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int k, su=1;
    cin>>k;
    string s="codeforces";
    int q[s.size()];
    for(int a=0; a<s.size(); a++) q[a]=1;
    int i=0;
    while(su<k)
    {
        su/=q[i], q[i]++, su*=q[i];
        i=(i+1)%(s.size());
    }
    for(int a=0; a<s.size(); a++)
    {
        for(int b=0; b<q[a]; b++) cout<<s[a];
    }
}
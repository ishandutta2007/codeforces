#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int k, p, su=0;
    cin>>k>>p;
    for(int a=1; a<=k; a++)
    {
        int x=a;
        vector <int> ch;
        while(x>0)
        {
            ch.push_back(x%10), x/=10;
        }
        x=a;
        for(int b=0; b<ch.size(); b++) x=x*10+ch[b];
        su+=x;
    }
    cout<<su%p;
}
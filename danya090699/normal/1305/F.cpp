#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    vector <int> sp;
    for(int a=0; a<n; a++)
    {
        scanf("%lld", &ar[a]);
        if(ar[a]>1) sp.push_back(ar[a]-1);
        sp.push_back(ar[a]);
        sp.push_back(ar[a]+1);
    }
    mt19937 gen(time(0));
    shuffle(sp.begin(), sp.end(), gen);
    set <int> de;
    int m=sp.size();
    for(int a=0; a<min(20ll, m); a++)
    {
        int x=sp[a];
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                de.insert(b);
                while(x%b==0) x/=b;
            }
        }
        if(x>1) de.insert(x);
    }
    int an=1e9;
    for(auto it=de.begin(); it!=de.end(); it++)
    {
        int x=(*it), su=0;
        for(int a=0; a<n; a++)
        {
            int os=ar[a]%x;
            if(os)
            {
                if(os<ar[a]) su+=min(os, x-os);
                else su+=x-os;
            }
        }
        an=min(an, su);
    }
    cout<<an;
}
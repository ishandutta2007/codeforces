#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n;
    cin>>n;
    int mask[n], p[1<<13], yk=0, an[n], va[13];
    for(int a=0; a<n; a++)
    {
        an[a]=0;
        while(__builtin_popcount(yk)!=6) yk++;
        mask[a]=yk, p[yk]=a, yk++;
    }
    for(int i=0; i<13; i++)
    {
        vector <int> sp;
        for(int a=0; a<n; a++) if(mask[a]&(1<<i)) sp.push_back(a+1);
        if(sp.size())
        {
            cout<<"? "<<sp.size();
            for(int a=0; a<sp.size(); a++) cout<<" "<<sp[a];
            cout<<"\n";
            cin>>va[i];
        }
        else va[i]=0;
    }
    for(int i=0; i<63; i++)
    {
        int x=0;
        for(int a=0; a<13; a++) if(va[a]&(1ll<<i)) x+=(1<<a);
        if(x)
        {
            for(int a=0; a<n; a++) an[a]+=(1ll<<i);
            if(__builtin_popcount(x)==6) an[p[x]]-=(1ll<<i);
        }
    }
    cout<<"!";
    for(int a=0; a<n; a++) cout<<" "<<an[a];
    cout<<"\n";
}
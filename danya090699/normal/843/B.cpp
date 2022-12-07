//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n, st, stva, x, be, bva=-1;
    cin>>n>>st>>x;
    st--;
    int q=min(n-1, 200);
    vector <int> av;
    for(int a=0; a<n; a++) if(a!=st) av.push_back(a);
    int ne, va;
    cout<<"? "<<st+1<<"\n";
    cin>>va>>ne;
    stva=va;
    if(va<x)
    {
        be=st, bva=va;
    }
    for(int a=0; a<q; a++)
    {
        int si=av.size();
        int p=(rand()*rand())%si;
        int nu=av[p];
        av.erase(av.begin()+p);
        cout<<"? "<<nu+1<<"\n";
        cin>>va>>ne;
        if(va<x and bva<va)
        {
            be=nu, bva=va;
        }
    }
    if(bva==-1) cout<<"! "<<stva;
    else
    {
        int cu=be;
        while(cu!=-1)
        {
            cout<<"? "<<cu+1<<"\n";
            cin>>va>>ne;
            if(va>=x)
            {
                cout<<"! "<<va;
                break;
            }
            if(ne!=-1) cu=ne-1;
            else cu=-1;
        }
        if(cu==-1) cout<<"! "<<-1;
    }
}
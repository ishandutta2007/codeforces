//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, u, q=0;
    cin>>n;
    vector <int> sp(1), ob(1);
    sp[0]=1e9, ob[0]=1;
    for(int a=0; a<n; a++)
    {
        int ty;
        cin>>ty;
        if(ty==1)
        {
            cin>>u;
            while(sp.back()<u)
            {
                sp.pop_back(), q++;
            }
        }
        if(ty==2)
        {
            while(ob.back()==0)
            {
                ob.pop_back(), q++;
            }
        }
        if(ty==3)
        {
            int x;
            cin>>x;
            sp.push_back(x);
            while(sp.back()<u)
            {
                sp.pop_back(), q++;
            }
        }
        if(ty==4) ob.push_back(1);
        if(ty==5) sp.push_back(1e9);
        if(ty==6) ob.push_back(0);
    }
    cout<<q;
}
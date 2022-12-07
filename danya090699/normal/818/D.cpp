#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+1;
vector <int> sv[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ca, fo=0;
    cin>>n>>ca;
    int po[n+1];
    po[0]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        po[a+1]=po[a];
        if(x==ca) po[a+1]++;
        sv[x].push_back(a+1);
    }
    for(int a=1; a<sz; a++)
    {
        if(a!=ca)
        {
            bool pos=1;
            for(int b=0; b<sv[a].size(); b++) if(po[sv[a][b]]>=b+1) pos=0;
            if(po[n]>sv[a].size()) pos=0;
            if(pos)
            {
                fo=1;
                cout<<a;
                break;
            }
        }
    }
    if(fo==0) cout<<-1;
}
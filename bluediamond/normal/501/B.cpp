#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int q;
map<string,bool>init;
map<string,bool>used;
map<string,string>nxt;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>q;
    while(q--)
    {
        string a,b;
        cin>>a>>b;
        if(used[a]==0)
        {
            init[a]=1;
        }
        if(used[b]==0)
        {
            nxt[a]=b;
        }
        used[a]=used[b]=1;
    }
    cout<<init.size()<<"\n";
    for(auto &it:init)
    {
        string a=it.first;
        cout<<a<<" ";
        while(nxt[a]!="")
        {
            a=nxt[a];
        }
        cout<<a<<"\n";
    }
    return 0;
}
/**


**/
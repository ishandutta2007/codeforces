#include <bits/stdc++.h>

using namespace std;

const int N=100000+5;

int n,cocacola[N];

struct info
{
    string a,b;
};


info v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i].a>>v[i].b;
    for(int i=1;i<=n;i++)
        cin>>cocacola[i];
    string last=min(v[cocacola[1]].a,v[cocacola[1]].b);
    for(int i=2;i<=n;i++)
    {
        string mi=min(v[cocacola[i]].a,v[cocacola[i]].b);
        string ma=max(v[cocacola[i]].a,v[cocacola[i]].b);
        if(last<mi)
        {
            last=mi;
            continue;
        }
        if(last<ma)
        {
            last=ma;
            continue;
        }
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}
/**


**/
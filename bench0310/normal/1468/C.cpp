#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    set<int> s;
    set<array<int,2>> t;
    vector<int> x(q+1,0);
    int id=1;
    for(int z=0;z<q;z++)
    {
        int tp;
        cin >> tp;
        if(tp==1)
        {
            cin >> x[id];
            s.insert(id);
            t.insert({x[id],q-id});
            id++;
        }
        else if(tp==2)
        {
            int a=(*s.begin());
            s.erase(a);
            t.erase({x[a],q-a});
            cout << a << " ";
        }
        else if(tp==3)
        {
            int b=q-(*t.rbegin())[1];
            s.erase(b);
            t.erase({x[b],q-b});
            cout << b << " ";
        }
    }
    cout << "\n";
    return 0;
}
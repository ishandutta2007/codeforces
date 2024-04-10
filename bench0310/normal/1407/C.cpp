#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> s;
    for(int i=1;i<=n;i++) s.insert(i);
    vector<int> res(n+1,0);
    auto query=[](int a,int b)->int
    {
        cout << "? " << a << " " << b << "\n";
        cout.flush();
        int x;
        cin >> x;
        return x;
    };
    while(s.size()>1)
    {
        auto it=s.begin();
        while(it!=s.end()&&next(it)!=s.end())
        {
            int a=(*it);
            it++;
            int b=(*it);
            it++;
            int one=query(a,b);
            int two=query(b,a);
            if(one>two)
            {
                res[a]=one;
                s.erase(a);
            }
            else
            {
                res[b]=two;
                s.erase(b);
            }
        }
    }
    res[*s.begin()]=n;
    cout << "! ";
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    cout.flush();
    return 0;
}
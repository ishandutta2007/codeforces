#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        auto q=[&](int a,int b)->int
        {
            cout << "? " << a << " " << b << endl;
            int x;
            cin >> x;
            if(x==-1) exit(0);
            return ((x==1)*a+(x==2)*b);
        };
        vector<int> v(1<<n);
        for(int i=1;i<=(1<<n);i++) v[i-1]=i;
        while(v.size()>=4)
        {
            vector<int> u;
            for(int i=0;i<(int)v.size();i+=4)
            {
                int x=q(v[i],v[i+2]);
                if(x==v[i]) u.push_back(q(v[i],v[i+3]));
                if(x==v[i+2]) u.push_back(q(v[i+1],v[i+2]));
                if(x==0) u.push_back(q(v[i+1],v[i+3]));
            }
            v=u;
        }
        if(v.size()==2) v={q(v[0],v[1])};
        cout << "! " << v[0] << endl;
    }
    return 0;
}
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
        vector<int> d;
        vector<int> p;
        for(int i=1;i*i<=n;i++)
        {
            if((n%i)!=0) continue;
            if(i>1) d.push_back(i);
            if(i<n/i) d.push_back(n/i);
        }
        int z=n;
        for(int i=2;i*i<=z;i++)
        {
            if((z%i)!=0) continue;
            p.push_back(i);
            while((z%i)==0) z/=i;
        }
        if(z>1) p.push_back(z);
        if(p.size()==1)
        {
            for(int a:d) cout << a << " ";
            cout << "\n0\n";
        }
        else if(p.size()==2)
        {
            if(d.size()==3)
            {
                for(int a:d) cout << a << " ";
                cout << "\n1\n";
            }
            else
            {
                vector<int> e;
                int one=p[0];
                int two=p[1];
                for(int a:d) if(a!=one&&a!=two) e.push_back(a);
                cout << one << " ";
                cout << e[0] << " ";
                cout << two << " ";
                for(int i=1;i<(int)e.size();i++) cout << e[i] << " ";
                cout << "\n0\n";
            }
        }
        else
        {
            vector<int> b;
            map<int,vector<int>> m;
            for(int i=0;i<(int)p.size();i++)
            {
                int x=p[i]*p[(i+1)%p.size()];
                b.push_back(x);
                m[x]={};
            }
            for(int a:d)
            {
                if(m.find(a)!=m.end()) continue;
                for(int i=0;i<(int)p.size();i++)
                {
                    if((a%p[i])==0)
                    {
                        m[p[i]*p[(i+1)%p.size()]].push_back(a);
                        break;
                    }
                }
            }
            for(int a:b)
            {
                for(int x:m[a]) cout << x << " ";
                cout << a << " ";
            }
            cout << "\n0\n";
        }
    }
    return 0;
}
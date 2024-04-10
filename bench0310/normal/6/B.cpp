#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    char p;
    cin >> n >> m >> p;
    string d[n];
    for(int i=0;i<n;i++) cin >> d[i];
    set<char> s;
    for(int o=0;o<n;o++)
    {
        for(int i=0;i<m;i++)
        {
            if(d[o][i]==p)
            {
                if(o!=0) s.insert(d[o-1][i]);
                if(i!=0) s.insert(d[o][i-1]);
                if(o!=n-1) s.insert(d[o+1][i]);
                if(i!=m-1) s.insert(d[o][i+1]);
            }
        }
    }
    cout << s.size()-s.count(p)-s.count('.') << endl;
    return 0;
}
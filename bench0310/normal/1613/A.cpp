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
        int x1,p1;
        cin >> x1 >> p1;
        string t1=to_string(x1);
        int n1=t1.size();
        int x2,p2;
        cin >> x2 >> p2;
        string t2=to_string(x2);
        int n2=t2.size();
        if(n1+p1<n2+p2) cout << "<\n";
        else if(n1+p1>n2+p2) cout << ">\n";
        else
        {
            t1+=string(max(0,int(t2.size()-t1.size())),'0');
            t2+=string(max(0,int(t1.size()-t2.size())),'0');
            if(t1<t2) cout << "<\n";
            else if(t1>t2) cout << ">\n";
            else cout << "=\n";
        }
    }
    return 0;
}
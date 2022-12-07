#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
int q[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    multiset <int, greater <int> > se;
    for(int a=0; a<sz; a++) se.insert(q[a]);
    int qq;
    cin>>qq;
    for(int a=0; a<qq; a++)
    {
        char ty;
        int x;
        cin>>ty;
        scanf("%d", &x);
        se.erase(se.find(q[x]));
        if(ty=='-') q[x]--;
        else q[x]++;
        se.insert(q[x]);
        auto it=se.begin();
        int q1=(*it);
        it++;
        int q2=(*it);
        it++;
        int q3=(*it);

        bool ok=0;
        if(q1>=4 and q2>=2 and q3>=2) ok=1;
        if(q1>=6 and q2>=2) ok=1;
        if(q1>=8) ok=1;
        if(q1>=4 and q2>=4) ok=1;

        printf(ok ? "YES\n" : "NO\n");
    }
}
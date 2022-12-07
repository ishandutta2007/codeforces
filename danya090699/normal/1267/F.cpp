#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int q[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, q1, q2;
    cin>>n>>m>>q1>>q2;
    if(q1>m-1 or q2>n-1)
    {
        cout<<"No";
        return 0;
    }
    vector <int> sm(q1), bg(q2), sp;
    for(int a=0; a<q1; a++) scanf("%d", &sm[a]);
    for(int a=0; a<q2; a++) scanf("%d", &bg[a]);
    while(sm.size()<m-1) sm.push_back(1);
    while(bg.size()<n-1) bg.push_back(n+m);
    while(sm.size())
    {
        if(q[sm.back()]==0 and sp.size())
        {
            sp.push_back(bg.back());
            q[bg.back()]++;
            bg.pop_back();
        }
        sp.push_back(sm.back());
        q[sm.back()]++;
        sm.pop_back();
    }
    while(bg.size())
    {
        sp.push_back(bg.back());
        q[bg.back()]++;
        bg.pop_back();
    }
    set <int> se;
    for(int a=1; a<=n+m; a++) if(q[a]==0) se.insert(a);
    cout<<"Yes\n";
    while(sp.size())
    {
        int v=*se.begin(), pr=sp.back();
        printf("%d %d\n", v, pr);
        se.erase(se.begin());
        q[pr]--;
        if(q[pr]==0) se.insert(pr);
        sp.pop_back();
    }
    printf("%d ", *se.begin());
    se.erase(se.begin());
    printf("%d", *se.begin());
}
#include <bits/stdc++.h>
using namespace std;
struct el
{
    int x, y, z, i;
};
bool comp(el a, el b)
{
    if(a.x!=b.x) return a.x<b.x;
    else
    {
        if(a.y!=b.y) return a.y<b.y;
        else return a.z<b.z;
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <el> sp, sp2, sp3;
    for(int a=0; a<n; a++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        sp.push_back({x, y, z, a+1});
    }
    sort(sp.begin(), sp.end(), comp);
    for(int a=0; a<sp.size(); a++)
    {
        if(a+1<sp.size() and sp[a].x==sp[a+1].x and sp[a].y==sp[a+1].y)
        {
            printf("%d %d\n", sp[a].i, sp[a+1].i);
            a++;
        }
        else sp2.push_back(sp[a]);
    }
    for(int a=0; a<sp2.size(); a++)
    {
        if(a+1<sp2.size() and sp2[a].x==sp2[a+1].x)
        {
            printf("%d %d\n", sp2[a].i, sp2[a+1].i);
            a++;
        }
        else sp3.push_back(sp2[a]);
    }
    for(int a=0; a<sp3.size(); a+=2) printf("%d %d\n", sp3[a].i, sp3[a+1].i);
}
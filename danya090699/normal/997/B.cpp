#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    vector <pair <int, int> > sp;
    for(int a=0; a<9; a++)
    {
        for(int b=0; b<49; b++) sp.push_back(make_pair(a*4+b*9, a+b));
    }
    for(int a=0; a<sp.size(); a++)
    {
        int va=sp[a].first, q=sp[a].second, ok=1;
        for(int b=0; b<sp.size(); b++) if(sp[b].first<va and (va-sp[b].first)%49==0) ok=0;
        if(ok and q<=n) an+=n-q+1;
    }
    cout<<an;
}
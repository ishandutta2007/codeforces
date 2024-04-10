#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    const int lim=500000;
    int n=0;
    vector<int> v[lim+1];
    while(q--)
    {
        int t,x;
        cin >> t >> x;
        if(t==1) v[x].push_back(++n);
        else
        {
            int y;
            cin >> y;
            if(x==y) continue;
            if(v[x].size()>v[y].size()) swap(v[x],v[y]);
            for(int a:v[x]) v[y].push_back(a);
            v[x].clear();
        }
    }
    vector<int> a(n+1,0);
    for(int i=1;i<=lim;i++) for(int j:v[i]) a[j]=i;
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    return 0;
}
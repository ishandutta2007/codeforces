#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    const int N=50;
    vector<int> pos(N+1,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        if(pos[a]==0) pos[a]=i;
    }
    while(q--)
    {
        int a;
        cin >> a;
        cout << pos[a] << " \n"[q==0];
        for(int i=1;i<=N;i++) if(i!=a&&pos[i]<pos[a]) pos[i]++;
        pos[a]=1;
    }
    return 0;
}
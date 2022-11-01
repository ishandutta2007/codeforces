#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> nxt[n+1];
    for(int i=n;i>=1;i--) nxt[a[i]].push_back(i);
    int res=0;
    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=x&&a[i]!=y)
        {
            res++;
            if(nxt[x].empty()) x=a[i];
            else if(nxt[y].empty()) y=a[i];
            else if(nxt[x].back()<nxt[y].back()) y=a[i];
            else x=a[i];
        }
        nxt[a[i]].pop_back();
    }
    cout << res << "\n";
    return 0;
}
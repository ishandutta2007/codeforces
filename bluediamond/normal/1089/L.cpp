#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;

int n,need;
int a[N];
int b[N];
vector<int>point[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>need;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        point[a[i]].push_back(b[i]);
    }
    int have=0;
    vector<int>ans;
    for(int i=1;i<=need;i++)
    {
        if(point[i].empty()) continue;
        sort(point[i].begin(),point[i].end());
        point[i].pop_back();
        for(auto &x:point[i])
        {
            ans.push_back(x);
        }
        have++;
    }
    sort(ans.begin(),ans.end());
    ll co=0LL;
    for(auto &x:ans)
    {
        if(have>=need)
        {
            break;
        }
        have++;
        co+=x;
    }
    cout<<co<<"\n";
    return 0;
}
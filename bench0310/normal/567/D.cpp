#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k,a,m;
    cin >> n >> k >> a >> m;
    set<int> s={0,n+1};
    auto c=[&](int x)->int{return (x+1)/(a+1);};
    int cnt=c(n);
    for(int i=1;i<=m;i++)
    {
        int x;
        cin >> x;
        auto it=s.lower_bound(x);
        int r=*it;
        it--;
        int l=*it;
        cnt-=c(r-l-1);
        cnt+=c(x-l-1);
        cnt+=c(r-x-1);
        s.insert(x);
        if(cnt<k)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
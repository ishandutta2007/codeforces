#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int l,r;
    cin >> l >> r;
    l--; r--;
    vector<array<int,3>> edges;
    auto add=[&](int a,int b,int c){edges.push_back({a,b,c});};
    int n=1;
    vector<int> one(2,0);
    vector<int> two(2,0);
    for(int i=2;i<=21;i++)
    {
        if((1<<(i-2))>r) break;
        n++;
        one.push_back(1<<(i-2));
        two.push_back((1<<(i-1))-1);
        two[i]=min(two[i],r);
        int now=two[i];
        for(int j=i-1;j>=1;j--)
        {
            int x=(two[j]-one[j]+1);
            if(x<=now-one[i]+1)
            {
                add(j,i,now-two[j]);
                now-=x;
            }
        }
    }
    int now=r;
    if(one[n]>=l)
    {
        add(n,n+1,1);
        now=one[n]-1;
    }
    for(int j=n-1;j>=1;j--)
    {
        int x=(two[j]-one[j]+1);
        if(x<=now-l+1)
        {
            add(j,n+1,now-two[j]+1);
            now-=x;
        }
    }
    cout << "YES\n";
    cout << n+1 << " " << edges.size() << "\n";
    for(auto [a,b,c]:edges) cout << a << " " << b << " " << c << "\n";
    return 0;
}
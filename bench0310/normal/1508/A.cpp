#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<string> v(3);
        for(int i=0;i<3;i++) cin >> v[i];
        string res;
        array<int,3> x={0,0,0};
        while(max({x[0],x[1],x[2]})<2*n)
        {
            array<int,2> c={0,0};
            for(int i=0;i<3;i++) c[v[i][x[i]]-'0']++;
            int r=(c[0]<c[1]);
            res+=(r+'0');
            for(int i=0;i<3;i++) if(v[i][x[i]]-'0'==r) x[i]++;
        }
        int good=-1;
        for(int i=0;i<3;i++) if(x[i]==2*n) good=i;
        assert(good!=-1);
        array<int,2> mx={-1,-1};
        for(int i=0;i<3;i++) if(i!=good) mx=max(mx,{x[i],i});
        int now=mx[1];
        assert(now!=-1);
        for(int i=x[now];i<2*n;i++) res+=v[now][i];
        assert((int)res.size()<=3*n);
        while((int)res.size()<3*n) res+='0';
        cout << res << "\n";
    }
    return 0;
}
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
        vector<array<int,2>> v(n);
        for(int j=0;j<2;j++) for(int i=0;i<n;i++) cin >> v[i][j];
        sort(v.begin(),v.end());
        if(v[0][0]!=1) v.insert(v.begin(),{1,1});
        n=v.size();
        auto solve_even=[&](int r,int c)->int
        {
            if(r==c) return r-1;
            else return (r-c)/2;
        };
        auto solve_odd=[&](int r,int c)->int
        {
            if(r==c) return 0;
            else return (r-c+1)/2;
        };
        auto go=[&](int a,int b,int c,int d)->int
        {
            int r=(c-a+1);
            if(((a+b)%2)==0) return solve_even(r,d-b+1);
            else return solve_odd(r,d-b+1);
        };
        int res=0;
        for(int i=0;i<n-1;i++) res+=go(v[i][0],v[i][1],v[i+1][0],v[i+1][1]);
        cout << res << "\n";
    }
    return 0;
}
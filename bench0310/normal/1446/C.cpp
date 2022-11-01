#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=200005;
vector<int> a(N,0);

int solve(vector<int> v,int p)
{
    if(v.size()<=2) return 0;
    vector<int> x[2];
    for(int id:v) x[(a[id]>>p)&1].push_back(id);
    if(x[0].empty()||x[1].empty()) return solve(v,p-1);
    int res=v.size();
    res=min(res,((int)x[0].size()-1)+solve(x[1],p-1));
    res=min(res,((int)x[1].size()-1)+solve(x[0],p-1));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        v.push_back(i);
    }
    cout << solve(v,30) << "\n";
    return 0;
}
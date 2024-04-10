#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<array<int,2>> res;

void merge_equal(vector<int> &a,vector<int> &b)
{
    assert(a.size()==b.size());
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        res.push_back({a[i],b[i]});
        a.push_back(b[i]);
    }
}

void merge_diff(vector<int> &a,vector<int> &b)
{
    assert(a.size()>b.size());
    int m=b.size();
    for(int i=0;i<m;i++)
    {
        res.push_back({a.back(),b[i]});
        b.push_back(a.back());
        a.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int now=1;
    vector<vector<int>> v;
    for(int i=13;i>=0;i--)
    {
        if(n&(1<<i))
        {
            vector<vector<int>> t;
            for(int j=0;j<(1<<i);j++) t.push_back({now++});
            for(int sz=1;sz<(1<<i);sz*=2)
            {
                for(int j=0;j+sz<(1<<i);j+=2*sz) merge_equal(t[j],t[j+sz]);
            }
            v.push_back(t[0]);
        }
    }
    while(v.size()>2)
    {
        if(v[v.size()-1].size()==v[v.size()-2].size())
        {
            merge_equal(v[v.size()-2],v[v.size()-1]);
            v.pop_back();
        }
        else merge_diff(v[0],v[v.size()-1]);
    }
    cout << res.size() << "\n";
    for(auto [a,b]:res) cout << a << " " << b << "\n";
    return 0;
}
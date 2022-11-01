#include <bits/stdc++.h>

using namespace std;

vector<int> sol;
int best=1000000;
int n,a,b;

void solve(int idx,vector<int> v,vector<int> h)
{
    if(idx==n-2)
    {
        while(h[idx-1]||h[idx])
        {
            v.push_back(idx);
            h[idx-1]-=min(b,h[idx-1]);
            h[idx]-=min(a,h[idx]);
            h[idx+1]-=min(b,h[idx+1]);
        }
        if((int)v.size()<best)
        {
            best=v.size();
            sol=v;
        }
    }
    else
    {
        while(h[idx-1])
        {
            v.push_back(idx);
            h[idx-1]-=min(b,h[idx-1]);
            h[idx]-=min(a,h[idx]);
            h[idx+1]-=min(b,h[idx+1]);
        }
        solve(idx+1,v,h);
        while(h[idx])
        {
            v.push_back(idx);
            h[idx-1]-=min(b,h[idx-1]);
            h[idx]-=min(a,h[idx]);
            h[idx+1]-=min(b,h[idx+1]);
            solve(idx+1,v,h);
        }
    }
}

int main()
{
    cin >> n >> a >> b;
    vector<int> h;
    int temp;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        h.push_back(temp+1);
    }
    vector<int> v;
    while(h[0]>0)
    {
        v.push_back(1);
        h[0]-=min(b,h[0]);
        h[1]-=min(a,h[1]);
        h[2]-=min(b,h[2]);
    }
    while(h[n-1]>0)
    {
        v.push_back(n-2);
        h[n-1]-=min(b,h[n-1]);
        h[n-2]-=min(a,h[n-2]);
        h[n-3]-=min(b,h[n-3]);
    }
    solve(1,v,h);
    cout << best << endl;
    for(int i=0;i<best;i++) cout << sol[i]+1 << " ";
    cout << endl;
    return 0;
}
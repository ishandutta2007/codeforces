#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> res;
    stack<int> two;
    stack<int> three;
    vector<int> a(n+1,0);
    vector<int> h(n+1,0);
    int now=1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]==1)
        {
            if(!two.empty())
            {
                int j=two.top();
                two.pop();
                res.push_back({h[j],i});
            }
            else if(!three.empty())
            {
                int j=three.top();
                three.pop();
                res.push_back({h[j],i});
                h[i]=now++;
                res.push_back({h[i],i});
            }
            else
            {
                h[i]=now++;
                res.push_back({h[i],i});
            }
        }
        else if(a[i]>1)
        {
            h[i]=now++;
            if(!three.empty())
            {
                int j=three.top();
                three.pop();
                res.push_back({h[j],i});
            }
            res.push_back({h[i],i});
            if(a[i]==2) two.push(i);
            else three.push(i);
        }
    }
    if(two.empty()&&three.empty())
    {
        cout << res.size() << "\n";
        for(auto [r,c]:res) cout << r << " " << c << "\n";
    }
    else cout << "-1\n";
    return 0;
}
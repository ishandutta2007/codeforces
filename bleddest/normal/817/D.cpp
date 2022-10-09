#include<bits/stdc++.h>

using namespace std;

long long sumOfMax(const vector<int>& a)
{
    int n = a.size();
    vector<int> greaterL(n);
    stack<pair<int, int> > s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top().first < a[i])
            s.pop();
        if(s.empty())
            greaterL[i] = -1;
        else
            greaterL[i] = s.top().second;
        s.push(make_pair(a[i], i));
    }
    while(!s.empty())
        s.pop();
    vector<int> greaterR(n);
    for(int i = n - 1; i >= 0; i--)
    {
        while(!s.empty() && s.top().first <= a[i])
            s.pop();
        if(s.empty())
            greaterR[i] = -1;
        else
            greaterR[i] = s.top().second;
        s.push(make_pair(a[i], i));
    }                  
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        int lefts = 0;
        if(greaterL[i] == -1)
            lefts = i + 1;
        else
            lefts = i - greaterL[i];
        int rights = 0;
        if(greaterR[i] == -1)
            rights = n - i;
        else
            rights = greaterR[i] - i;
        ans += lefts * 1ll * rights * 1ll * a[i];
    }
    return ans;
}

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    long long ans = sumOfMax(a);
    for(int i = 0; i < n; i++)
        a[i] *= -1;
    ans += sumOfMax(a);
    cout << ans << endl;
}
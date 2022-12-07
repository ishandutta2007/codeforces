#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, d, m, an=0;
    cin>>n>>d>>m;
    vector <int> sm, bg;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        if(x>m) bg.push_back(x);
        else sm.push_back(x);
    }
    sort(sm.begin(), sm.end(), greater <int>());
    sm.insert(sm.begin(), 0);
    for(int a=1; a<sm.size(); a++) sm[a]+=sm[a-1];

    sort(bg.begin(), bg.end(), greater <int>());
    bg.insert(bg.begin(), 0);
    for(int a=1; a<bg.size(); a++) bg[a]+=bg[a-1];

    for(int a=0; a<bg.size(); a++)
    {
        if(a+a*d>=bg.size()-1 and (a-1)*d<=n-a)
        {
            int q=max((a-1)*d, bg.size()-1-a);

            an=max(an, bg[a]+sm[n-a-q]);
        }
    }
    cout<<an;
}
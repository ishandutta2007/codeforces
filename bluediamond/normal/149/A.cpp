#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int need;
    cin>>need;
    vector<int>v(12);
    for(int i=0;i<12;i++)
        cin>>v[i];
    if(need==0)
    {
        cout<<"0\n";
        return 0;
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<12;i++)
    {

        need-=v[i];
        if(need<=0)
        {
            cout<<i+1<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";
    return 0;
}
/**
**/
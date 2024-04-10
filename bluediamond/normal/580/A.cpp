#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int cur=0;
    int res=0;
    for(int i=1;i<n;i++)
    {
        int sg=(v[i-1]<=v[i]);
        if(sg==1)
        {
            cur++;
        }
        else
        {
            cur=0;
        }
        res=max(res,cur);
    }
    res++;
    cout<<res<<"\n";
    return 0;
}
/**


**/
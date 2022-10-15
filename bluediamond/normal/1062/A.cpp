#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int v[105];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    v[1]=0;
    v[n+2]=1001;
    for(int i=2;i<=n+1;i++)
    {
        cin>>v[i];
    }
    int ans=0;
    for(int st=2;st<=n+1;st++)
    {
        for(int dr=st;dr<=n+1;dr++)
        {
            if(v[dr]-v[st]!=dr-st)
            {
                break;
            }
            if(v[dr+1]-v[st-1]!=dr+1-(st-1))
            {
                break;
            }
            ans=max(ans,dr-st+1);
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/
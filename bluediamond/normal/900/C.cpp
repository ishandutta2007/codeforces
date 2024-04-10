#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)1e5+5;
int n,v[N],e[N];
int delta[N];
int ma=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int ma1=0;
    int ma2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        if(v[i]>ma1)
        {
            ma2=ma1;
            ma1=v[i];
            delta[ma1]--;
        }
        else
        {
            if(v[i]>ma2)
            {
                ma2=v[i];
                delta[ma1]++;
            }
        }
    }
    int ans=1;
    for(int i=2;i<=n;i++)
    {
        if(delta[i]>delta[ans])
        {
            ans=i;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100+5;
const int L=(int)1e6+5;
int n;
string s[N];
int v[N];
int cnt=0,ans;
int ap[L];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i]>>v[i];
        ap[v[i]]++;
        if(ap[v[i]]==1 && s[i]=="-")
        {
            cnt++;
        }
    }
    ans=cnt;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=="-") cnt--;
        else
            cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/
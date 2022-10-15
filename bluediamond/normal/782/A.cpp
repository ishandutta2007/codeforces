#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,cnt=0,ans=0;
int ap[100000+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=2*n;i++)
    {
        int a;
        cin>>a;
        if(ap[a])
            cnt--;
        else
            ap[a]=1,cnt++;
        ans=max(ans,cnt);
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/
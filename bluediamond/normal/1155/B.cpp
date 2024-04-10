#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;

int n;
string s;
int unde[N],p=0;

int32_t main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        cin>>s;
        s="."+s;
        for(int i=1;i<=n;i++)
        {
                if(s[i]=='8')
                {
                        unde[++p]=i;
                }
        }
        int mv=(n-11)/2;
        if(mv>=p)
        {
                cout<<"NO\n";
                return 0;
        }
        int poz=unde[mv+1];
        if(poz<=mv*2+1)
        {
                cout<<"YES\n";
        }
        else
        {
                cout<<"NO\n";
        }
        return 0;
}
/**

13
8308011223344


**/
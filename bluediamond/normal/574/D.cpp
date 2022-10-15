#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;


int n;
int h[N];
int freak1[N];
int freak2[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>h[i];
        }
        for(int i=1;i<=n;i++)
        {
                freak1[i]=min(freak1[i-1]+1,h[i]);
        }
        for(int i=n;i>=1;i--)
        {
                freak2[i]=min(freak2[i+1]+1,h[i]);
        }
        int last=0;
        for(int i=1;i<=n;i++)
        {
                int first=min(freak1[i],freak2[i]);
                last=max(last,first);
        }
        cout<<last<<"\n";
        return 0;
}
/**

**/
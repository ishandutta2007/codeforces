#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;

int n,s;
int a[N];
int b[N];

inline void print(string ans)
{
    cout<<ans<<"\n";
    exit(0);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(a[1] && a[s])
    {
        print("YES");
    }
    if(a[1] && b[s])
    {
        for(int i=s+1;i<=n;i++)
        {
            if(a[i] && b[i])
            {
                print("YES");
            }
        }
    }
    print("NO");
    return 0;
}
/**

**/
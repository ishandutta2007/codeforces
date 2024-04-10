#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        string s;
        int n;
        cin>>n>>s;
        for(int i=0;i+1<n;i++)
        {
                if(s[i+1]<s[i])
                {
                        cout<<"YES\n";
                        cout<<i+1<<" "<<i+2<<"\n";
                        return 0;
                }
        }
        cout<<"NO\n";
        return 0;
}
/**

**/
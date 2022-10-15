#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

bool cmp(string a,string b)
{
        if(a.size()==b.size())
                return a<b;
        return a.size()<b.size();
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        string s;
        cin>>s;

        int ans=0;
        string a="1";
        while(cmp(a,s))
        {
                ans++;
                a+="00";
        }
        cout<<ans<<"\n";

        return 0;
}
/**

**/
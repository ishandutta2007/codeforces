#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map <char,int> f;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        while(n--)
        {
                string s;
                cin>>s;
                f[s[0]]++;
        }
        int rs=0;
        for(auto &it:f)
        {
                int a=it.second/2;
                int b=it.second-a;
                rs+=a*(a-1)/2;
                rs+=b*(b-1)/2;
        }
        cout<<rs<<"\n";
        return 0;
}
/**

**/
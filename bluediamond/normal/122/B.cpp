#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int f[15];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    for(auto &it:s)
    {
        f[it-'0']++;
    }
    if(f[4]==0 && f[7]==0)
    {
        cout<<"-1\n";
        return 0;
    }
    else
    {
        if(f[4]>=f[7])
        {
            cout<<"4\n";
        }
        else
        {
            cout<<"7\n";
        }
    }
    return 0;
}
/**


**/
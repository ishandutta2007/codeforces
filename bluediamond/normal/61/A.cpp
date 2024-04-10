#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a,b;
    cin>>a>>b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            cout<<"1";
        else
            cout<<"0";
    }
    cout<<"\n";
    return 0;
}
/**

**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a;
    cin>>a;
    int n=a.size();
    for(int i=2;i<n;i++)
    {
        bool e_a=0;
        bool e_b=0;
        bool e_c=0;
        if(a[i]=='A' || a[i-1]=='A' || a[i-2]=='A')e_a=1;
        if(a[i]=='B' || a[i-1]=='B' || a[i-2]=='B')e_b=1;
        if(a[i]=='C' || a[i-1]=='C' || a[i-2]=='C')e_c=1;
        if(e_a==1 && e_b==1 && e_c==1)
        {
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    return 0;
}
/**

**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

string s;
int n,k;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>k;
    n=s.size();
    if(n%k)
    {
        cout<<"NO\n";
        return 0;
    }
    k=n/k;
    for(int st=0;st<n;st+=k)
    {
        int dr=st+k-1;
        string a,b;
        for(int i=st;i<=dr;i++)
        {
            a+=s[i];
        }
        b=a;
        reverse(b.begin(),b.end());
        if(a!=b)
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}
/**


**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

string a;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>a;
    n=a.size();
    bool ab=0,ba=0;
    bool ok=0;
    for(int i=0;i+2<n;i++)
    {
        if(a[i+1]=='A' && a[i+2]=='B' && ba) ok=1;
        if(a[i+1]=='B' && a[i+2]=='A' && ab) ok=1;
        if(a[i]=='A' && a[i+1]=='B') ab=1;
        if(a[i]=='B' && a[i+1]=='A') ba=1;
    }
    if(ok) cout<<"YES\n"; else
    cout<<"NO\n";
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a=0,d=0,n;
    string s; cin>>n>>s;
    for(auto itr:s)
    {
        if(itr=='A') a++;
        else d++;
    }
    if(a==d) cout<<"Friendship\n";
    if(a>d) cout<<"Anton\n";
    if(a<d) cout<<"Danik\n";
}
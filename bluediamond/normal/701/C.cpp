#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

int f(char ch) {return ch;}
const int N=1000;
int x[N],total=0;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; string a; cin>>n>>a;
    for(auto itr:a)
    {
        x[f(itr)]++; if(x[f(itr)]==1) total++;
    }
    for(auto itr:a)
    {
        x[f(itr)]--;
    }
    int ans=(1<<30);
    int st=0;
    int cur=0;
    for(int dr=0;dr<n;dr++)
    {
        x[f(a[dr])]++; if(x[f(a[dr])]==1) cur++;
        while(cur==total)
        {
            ans=min(ans,dr-st+1);
            x[f(a[st])]--; if(x[f(a[st])]==0) cur--;
            st++;
        }
    }
    cout<<ans<<"\n";
}
/**

**/
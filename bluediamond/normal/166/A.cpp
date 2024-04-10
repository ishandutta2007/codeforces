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
    int n,k; cin>>n>>k;
    vector< pair<int,int> >v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i].ff>>v[i].ss;
        v[i].ff*=-1;
    }
    sort(v.begin(),v.end());
    int st=0;
    while(st<n)
    {
        int dr=st;
        while(dr+1<n && v[dr+1]==v[st])
            dr++;
        if(st+1<=k && k<=dr+1) {cout<<dr-st+1<<"\n"; return 0;}
        st=dr+1;
    }
}
/**

**/
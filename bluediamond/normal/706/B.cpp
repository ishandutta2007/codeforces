#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    int q; cin>>q;
    while(q--)
    {
        int x; cin>>x;
        int st=0;
        int dr=n-1;
        int lst=-1;
        while(st<=dr)
        {
            int mid=(st+dr)/2;
            if(v[mid]<=x)
            {
                lst=mid;
                st=mid+1;
            }
            else dr=mid-1;
        }
        cout<<lst+1<<"\n";
    }
}
/**

**/
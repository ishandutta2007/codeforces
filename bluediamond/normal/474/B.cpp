#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back

const int N=1e5+5;
int n,s[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        s[i]+=s[i-1];
    }
    int q; cin>>q;
    while(q--)
    {
        int x; cin>>x;
        int st=1,dr=n;
        int lst=0;
        while(st<=dr)
        {
            int mid=(st+dr)/2;
            if(x>s[mid])
            {
                st=mid+1;
            }
            else
            {
                lst=mid;
                dr=mid-1;
            }
        }
        cout<<lst<<"\n";
    }
}
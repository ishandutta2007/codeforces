#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int)1e5+7;
ll len,k;
int n;
ll a[N];

ll kek(ll p)
{
        return 1+(p-1)/k;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        cin>>len>>n>>k;

        for(int i=1;i<=n;i++)
                cin>>a[i];


        int i=1,c=0;
        while(i<=n)
        {
                int j=i;
                while(j+1<=n && kek(a[i]-(i-1))==kek(a[j+1]-(i-1)))
                        j++;
                c++;
                i=j+1;
        }

        cout<<c<<"\n";

        return 0;
}
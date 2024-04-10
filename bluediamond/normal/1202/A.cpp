#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)1e5+7;
int x[N],y[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        int t;
        cin>>t;
        while(t--)
        {
                string a,b;
                cin>>a>>b;
                reverse(a.begin(),a.end());
                reverse(b.begin(),b.end());
                int n=a.size(),m=b.size();
                int fi=0;
                while(b[fi]=='0')
                        fi++;
                int sc=fi;
                while(a[sc]=='0')
                        sc++;
                cout<<sc-fi<<"\n";
        }

        return 0;
}
/**



**/
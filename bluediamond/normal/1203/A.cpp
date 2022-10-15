#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

        bool ishome=0;

        if(ishome)
        {
                freopen("__input__","r",stdin);
        }
        else
        {
                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        int q;
        cin>>q;
        while(q--)
        {
                int n;
                cin>>n;
                vector <int> a(n);
                int p;
                for(int i=0;i<n;i++)
                {
                        cin>>a[i];
                        a[i]--;
                        if(a[i]==0)
                                p=i;
                }
                bool aa=1,bb=1;
                int want=0;
                for(int j=p;j<p+n;j++)
                {
                        if(a[j%n]!=want)
                                aa=0;
                        want++;
                }
                p++;
                want=n-1;
                for(int j=p;j<p+n;j++)
                {
                        if(a[j%n]!=want)
                                bb=0;
                        want--;
                }
                if(aa||bb)
                        cout<<"YES\n";
                else
                        cout<<"NO\n";
        }



        return 0;
}
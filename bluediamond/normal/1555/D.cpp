#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
///#define int ll

const int N=(int) 2e5+7;
int n, q, v[N], pre[6][N];
string s;


signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);

      //  freopen ("input", "r", stdin);


        cin>>n>>q>>s;
        for (int i=1; i<=n; i++)
        {
                v[i]=s[i-1]-'a';
        }
        int ind=0;
        for (int a=0; a<3; a++)
        {
                for (int b=0; b<3; b++)
                {
                        if (a==b) continue;
                        int c=3-a-b;

                        for (int i=1; i<=n; i++)
                        {
                                int now=0;
                                if ((i-1)%3==0) now=(v[i]!=a);
                                if ((i-1)%3==1) now=(v[i]!=b);
                                if ((i-1)%3==2) now=(v[i]!=c);
                                pre[ind][i]=pre[ind][i-1]+now;
                        }
                        ind++;
                }


        }
        assert(ind==6);

        while (q--)
        {
                int l, r, sol=(int) 1e9;
                cin>>l>>r;
                sol=min(sol, pre[0][r]-pre[0][l-1]);
                sol=min(sol, pre[1][r]-pre[1][l-1]);
                sol=min(sol, pre[2][r]-pre[2][l-1]);
                sol=min(sol, pre[3][r]-pre[3][l-1]);
                sol=min(sol, pre[4][r]-pre[4][l-1]);
                sol=min(sol, pre[5][r]-pre[5][l-1]);
                cout<<sol<<"\n";
        }


}
#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[200005], b[200005], c[200005], x[200005];
vector <int> v[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=1;i<=k;i++)
        cin >> c[i];

    for(int i=0;i<n;i++)
        b[a[i]]++;

    int ans=0;
    int s=0;

    for(int i=k;i>=1;i--)
    {
        s+=b[i];
        ans=max(ans, (s+c[i]-1)/c[i]);
    }

    cout << ans << "\n";



    for(int i=k;i>=1;i--)
        {
            int j=0;
            while(b[i]!=0 && j<ans)
            {
                while(b[i]>0 && x[j]<c[i])
                {
                    x[j]++;
                    b[i]--;
                    v[j].push_back(i);
                }

                int L=j;
                int R=ans-1;
                while(R-L>1)
                {
                    int M=(L+R)/2;
                    if(x[M]<c[i])
                        R=M;
                    else L=M;
                }

                j=R;
            }



        }


    for(int j=0;j<ans;j++)
    {
        cout << v[j].size() << ' ';
        for(auto to:v[j])
            cout << to << ' ';
        cout << "\n";
    }



}
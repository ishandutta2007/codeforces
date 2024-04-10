#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi

using namespace std;

int n, a[100005];
vector <int> v[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    for(int i=0;i<n;i++)
    {
        int s=sqrt(a[i]);
        for(int j=2;j<=s;j++)
        {
            if(a[i]%j==0)
            {
                int k=0;
                while(a[i]%j==0)
                {
                    a[i]/=j;
                    k++;
                }
                v[j].push_back(k);
            }
        }
        if(a[i]>1)
            v[a[i]].push_back(1);
    }



    for(int i=0;i<200005;i++)
        sort(v[i].begin(), v[i].end());

    /*for(auto to:v[2])
        cout << to << ' ';
    cout << endl;*/

    int ans=1;
    for(int i=0;i<200005;i++)
    {
        int j=min(1-n+(int)v[i].size(), (int)v[i].size()-1);
        if(j>=0)
            {
                //cout << v[i][j] << ' ';
                for(int k=0;k<v[i][j];k++)
                    ans*=i;
            }
    }
    cout << ans;
}
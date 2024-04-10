#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 1;

int c[N], cnt[500][N], tmp[N], tmp2[N];
vector<int> norm;
int n,m;

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        cin >> tmp[i];
        if (tmp[i] < N) c[tmp[i]]++;
        tmp2[i] = tmp[i];
    }

    sort(tmp2, tmp2+n);
    for (int i=0; i<n; i++)
        if (tmp2[i] < N && c[tmp2[i]]>=tmp2[i])
            if (i==0 || tmp2[i]!=tmp2[i-1])
                norm.push_back(tmp2[i]);

    for (int i=1; i<=n; i++)
        for (int j=0; j<norm.size(); j++)
        {
            cnt[j][i]=cnt[j][i-1];
            if (norm[j] == tmp[i-1])cnt[j][i]++;
        }

    for (;m;m--)
    {
        int l,r,ans=0;
        cin >> l >> r;
        for (int i=0; i<norm.size(); i++)
            ans += (norm[i] == (cnt[i][r]-cnt[i][l-1]));
        cout << ans << endl;
    }
    return 0;
}
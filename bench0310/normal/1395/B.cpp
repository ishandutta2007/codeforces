#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,r,c;
    cin >> n >> m >> r >> c;
    vector<bool> col(m+1,0);
    int idx=1;
    auto out=[&](){cout << r << " " << c << "\n";};
    for(int i=1;i<=m;i++)
    {
        col[c]=1;
        out();
        int src=r;
        for(int o=1;o<=n;o++)
        {
            if(o!=src)
            {
                r=o;
                out();
            }
        }
        while(col[idx]==1) idx++;
        c=idx;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<vector<int>> rows(n,vector<int>(m,0));
        vector<int> one(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin >> rows[i][j];
            one[i]=rows[i][0];
        }
        sort(one.begin(),one.end());
        vector<vector<int>> columns(m,vector<int>(n,0));
        int id=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) cin >> columns[i][j];
            vector<int> tmp=columns[i];
            sort(tmp.begin(),tmp.end());
            if(one==tmp) id=i;
        }
        for(int a:columns[id])
        {
            for(vector<int> &v:rows)
            {
                if(v[0]==a) for(int i=0;i<m;i++) cout << v[i] << " \n"[i==m-1];
            }
        }
    }
    return 0;
}
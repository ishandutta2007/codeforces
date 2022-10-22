#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<int,bool> m;
    int n,k,a;
    cin >> n >> k;
    int cant=0;
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(!m[a])
        {
            if(cant==k)
            {
                m[q.front()]=0;
                q.pop();
                cant--;
            }
            q.push(a);
            m[a]=1;
            cant++;
        }
    }

    db(q.size())
    vector<int> res;
    while(!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }

    reverse(res.begin(),res.end());

    for(int i=0;i<res.size();i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
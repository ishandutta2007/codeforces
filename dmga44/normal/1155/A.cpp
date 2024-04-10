#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    pii res=pii(-1,0);
    for(int i=0;i<n;i++)
    {
        int v=s[i]-'a';
        if(v<res.first)
        {
            db("YES")
            cout << res.second << ' ' << i+1 << '\n';
            return 0;
        }
        res=max(res,pii(v,i+1));
    }
    db("NO")

    return 0;
}
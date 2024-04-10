#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 200

bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        bool res=1;
        for(int i=0;i<n/2;i++)
        {
            mk[s[i]-1]=1;
            mk[s[i]+1]=1;
            if(!mk[s[n-i-1]-1] && !mk[s[n-i-1]+1])
                res=0;
            mk[s[i]-1]=0;
            mk[s[i]+1]=0;
        }
        if(res)
            db("YES")
        else
            db("NO")
    }

    return 0;
}
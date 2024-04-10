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

    int t;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        int x;
        cin >> x;
        string n;
        cin >> n;
        bool res=0;
        for(int j=0;j<(int)(n.size())-10;j++)
            if(n[j]=='8')
                res=1;
        if(res)
            db("YES")
        else
            db("NO")
    }

    return 0;
}
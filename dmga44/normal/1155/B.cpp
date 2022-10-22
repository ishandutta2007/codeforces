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
    cin >> n;
    int m8=0;
    for(int i=0;i<=(n-11);i++)
    {
        char c;
        cin >> c;
        if(c=='8')
            m8++;
    }

    if(m8>(n-11)/2)
        db("YES")
    else
        db("NO")

    return 0;
}
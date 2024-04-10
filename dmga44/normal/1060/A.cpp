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
    int x=0;
    for(int i=0;i<n;i++)
    {
        char a;
        cin >> a;
        if(a=='8')
            x++;
    }
    db(min(x,n/11))

    return 0;
}
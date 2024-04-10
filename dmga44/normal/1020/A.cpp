#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,h,a,b,k,x,w,y,z;
    cin >> n >> h >> a >> b >> k;
    while(k--)
    {
        cin >> w >> x >> y >> z;
        if(x>=a && x<=b)
            cout << abs(w-y)+abs(x-z) << '\n';
        else if(w!=y)
        {
            if(x>b)
                cout << x-b+abs(w-y)+abs(b-z) << '\n';
            else
                cout << a-x+abs(w-y)+abs(a-z) << '\n';
        }
        else
            cout << abs(x-z) << '\n';
    }


    return 0;
}
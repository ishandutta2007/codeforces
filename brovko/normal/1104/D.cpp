#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    while(true)
    {
        cin >> s;
        if(s=="end")
            return 0;
        int c='y';
        int L=0;
        int R=1;
        while(c=='y')
        {
            cout << "? " << L << ' ' << R << endl;
            char x;
            cin >> x;
            c=x;

            if(c=='y')
            {
                L*=2;
                R*=2;
                if(L==0)
                    L++;
            }
        }
        while(R-L>1)
        {
            int M=(L+R)/2;
            cout << "? " << L << ' ' << M << endl;
            char x;
            cin >> x;
            if(x=='x')
                R=M;
            else L=M;
        }
        cout << "! " << R << endl;
    }
}
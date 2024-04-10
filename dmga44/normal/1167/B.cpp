#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    vector<int> v;
    v.push_back(4);
    v.push_back(8);
    v.push_back(15);
    v.push_back(16);
    v.push_back(23);
    v.push_back(42);
    cout << "? 1 2\n";
    cout << "? 1 3\n";
    cout << "? 1 4\n";
    cout << "? 1 5\n";
    fflush(stdout);
    int a[4];
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    while(1)
    {
        bool ok=1;
        for(int i=0;i<4;i++)
            ok&=(a[i]==(v[0]*v[i+1]));
        if(ok)
        {
            cout << "! ";
            for(int i=0;i<6;i++)
                cout << v[i] << ' ';
            cout << '\n';
            fflush(stdout);
            break;
        }
        next_permutation(v.begin(),v.end());
    }

    return 0;
}
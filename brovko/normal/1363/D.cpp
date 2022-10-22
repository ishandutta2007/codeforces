#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int t, n, k, c[1005], used[1005];
vector <int> v[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        for(int i=0;i<1005;i++)
            used[i]=0;

        cin >> n >> k;
        for(int i=0;i<k;i++)
        {
            cin >> c[i];
            v[i].erase(v[i].begin(), v[i].end());
            for(int j=0;j<c[i];j++)
            {
                int x;
                cin >> x;
                v[i].push_back(x);
            }
        }

        cout << "? " << n << ' ';
        for(int i=0;i<n;i++)
            cout << i+1 << ' ';
        cout << endl;
        int Max;
        cin >> Max;

        int L=-1;
        int R=k;
        while(R-L>1)
        {
            int M=(L+R)/2;
            cout << "? ";
            int s=0;

            for(int i=0;i<=M;i++)
                for(auto to:v[i])
                    s++;

            cout << s << ' ';
            for(int i=0;i<=M;i++)
                for(auto to:v[i])
                    cout << to << ' ';
            cout << endl;
            int x;
            cin >> x;
            if(x==Max)
                R=M;
            else L=M;
        }

        for(auto to:v[R])
            used[to]=1;

        int s=0;
        for(int i=1;i<=n;i++)
            if(used[i]==0)
            s++;

        int x=Max;

        if(s)
        {
            cout << "? ";
            cout << s << ' ';
            for(int i=1;i<=n;i++)
                if(used[i]==0)
                cout << i << ' ';

            cout << endl;
            cin >> x;
        }


        cout << "! ";
        for(int i=0;i<k;i++)
            if(i==R)
                cout << x << ' ';
            else cout << Max << ' ';

        cout << endl;

        string S;
        cin >> S;
        if(S=="Incorrect")
            return 0;
    }
}
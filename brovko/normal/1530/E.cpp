#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, b[128];
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> s;
        int n = s.size();

        for(int i = 'a'; i <= 'z'; i++)
            b[i] = 0;

        for(auto to:s)
            b[to]++;

        int F = 0;

        for(int i = 'a'; i <= 'z'; i++)
            if(b[i] == 1 && F == 0)
            {
                F = 1;
                cout << (char) i;
                b[i]--;

                for(int j = 'a'; j <= 'z'; j++)
                    for(int k = 0; k < b[j]; k++)
                        cout << (char) j;

                cout << "\n";
            }

        if(F)
            continue;

        char a = 'a';

        while(b[a] == 0)
            a++;

        F = 1;

        if(2 * b[a] - 4 > n - 2)
            F = 0;

        if(F)
        {
            b[a] -= 2;
            cout << a << a;

            int m = n - 2;
            char z = a + 1;

            for(int i = 0; i < n - 2; i++)
            {
                if(i % 2 != 0 && b[a] > 0)
                {
                    cout << a;
                    b[a]--;
                }
                else
                {
                    while(b[z] == 0)
                        z++;

                    b[z]--;
                    cout << z;
                }
            }

            cout << "\n";
        }
        else if(b[a] == n)
        {
            for(int i = 0; i < n; i++)
                cout << a;

            cout << "\n";
        }
        else
        {
            cout << a;
            b[a]--;

            char z = a + 1;

            while(z <= 'z' && b[z] == 0)
                z++;

            cout << z;
            b[z]--;

            char y = z + 1;

            while(y <= 'z' && b[y] == 0)
                y++;

            if(y <= 'z')
            {
                for(int i = 0; i < b[a]; i++)
                    cout << a;

                cout << y;
                b[y]--;

                for(char i = z; i <= 'z'; i++)
                    for(int j = 0; j < b[i]; j++)
                        cout << i;

                cout << "\n";
            }
            else
            {
                //cout << "GGG" << endl;

                while(b[z]--)
                    cout << z;

                while(b[a]--)
                    cout << a;

                cout << "\n";
            }
        }
    }
}
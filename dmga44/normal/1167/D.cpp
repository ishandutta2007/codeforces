#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 400005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;
    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            if(s2==s1)
            {
                s1++;
                cout << 0;
            }
            else
            {
                s2++;
                cout << 1;
            }
        }
        else
        {
            if(s2==s1)
            {
                s2--;
                cout << 1;
            }
            else
            {
                s1--;
                cout << 0;
            }
        }
    }

    return 0;
}
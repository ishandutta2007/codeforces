#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n&1)
    {
        db(":(")
        return 0;
    }

    int cont[2];
    cont[0]=cont[1]=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
            continue;
        int t=0;
        if(s[i]==')')
            t=1;

        cont[t]++;
    }
    int fal=(n/2)-cont[0];

    int d=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='?')
        {
            if(fal)
            {
                s[i]='(';
                fal--;
            }
            else
                s[i]=')';
        }

        if(s[i]=='(')
            d++;
        else if(s[i]==')')
            d--;

        if(d<0 || (!d && i!=n-1))
        {
            db(":(")
            return 0;
        }
    }

    if(!d)
        db(s)
    else
        db(":(")

    return 0;
}
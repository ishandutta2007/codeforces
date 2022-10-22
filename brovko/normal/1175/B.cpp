#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;
const int INF=((1ll << 32)-1);

int n, x, ans;
string s;
vector <int> v;

void NO()
{
    cout << "OVERFLOW!!!";
    exit(0);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    x=1;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        if(s=="add")
        {
            ans+=x;
            if(ans>INF)
                NO();
        }
        if(s=="end")
        {
            x/=v[(int)v.size()-1];
            v.pop_back();
        }
        if(s=="for")
        {
            int p;
            cin >> p;
            if(x*p<=INF)
                {
                    x*=p;
                    v.push_back(p);
                }
            else
            {
                int k=1;
                while(k)
                {
                    i++;
                    cin >> s;
                    if(s=="add")
                        NO();
                    else if(s=="end")
                        k--;
                    else
                    {
                        cin >> p;
                        k++;
                    }
                }
            }
        }
    }
    cout << ans;
}
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ll x=0;
    cin >> n;
    stack<ll> mul;
    mul.push(1);
    ll m=(1ll<<32);
    while(n--)
    {
        string s;
        cin >> s;
        if(s=="add")
        {
            if(x!=-1)
            {
                if(mul.top()!=-1)
                {
                    x+=mul.top();
                    if(x>=m)
                        x=-1;
                }
                else
                    x=-1;
            }
        }
        else if(s=="end")
            mul.pop();
        else
        {
            ll y;
            cin >> y;
            if(mul.top()==-1)
                mul.push(-1);
            else
            {
                if(y*mul.top()>=m)
                    mul.push(-1);
                else
                    mul.push(y*mul.top());
            }
        }
    }
    if(x==-1)
        db("OVERFLOW!!!")
    else
        db(x)

    return 0;
}
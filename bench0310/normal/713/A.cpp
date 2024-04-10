#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    vector<int> v((1<<18),0);
    auto f=[](ll x)->int
    {
        int y=0;
        for(int i=0;i<18;i++)
        {
            if((x%10)&1) y^=(1<<i);
            x/=10;
        }
        return y;
    };
    while(t--)
    {
        char c;
        cin >> c;
        if(c=='+'||c=='-')
        {
            ll x;
            cin >> x;
            int y=f(x);
            if(c=='+') v[y]++;
            else v[y]--;
        }
        else
        {
            string s;
            cin >> s;
            cout << v[stoi(s,0,2)] << "\n";
        }
    }
    return 0;
}
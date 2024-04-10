#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](double l,double r)->double{return uniform_real_distribution<double>(l,r)(gen);};
    vector<int> mistakes(n,0);
    const double b=9.0/10;
    while(m--)
    {
        string s;
        cin >> s;
        int mn=mistakes[0];
        for(int i=0;i<n;i++) mn=min(mn,mistakes[i]);
        double W=0;
        vector<double> w(n,0);
        for(int i=0;i<n;i++)
        {
            w[i]=pow(b,mistakes[i]-mn);
            W+=w[i];
        }
        double x=rng(0,W);
        for(int i=0;i<n;i++)
        {
            if(i==n-1||x<w[i])
            {
                cout << s[i] << "\n";
                cout.flush();
                break;
            }
            x-=w[i];
        }
        int a;
        cin >> a;
        for(int i=0;i<n;i++) if((s[i]-'0')!=a) mistakes[i]++;
    }
    return 0;
}
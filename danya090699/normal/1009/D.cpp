#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    if(m<n-1) cout<<"Impossible";
    else
    {
        vector <pair <int, int> > an;
        for(int a=2; a<=n; a++) an.push_back(make_pair(1, a));
        m-=n-1;
        if(m)
        {
            for(int a=2; a<=n; a++)
            {
                for(int b=a-1; b>1; b--)
                {
                    if(__gcd(a, b)==1)
                    {
                        an.push_back(make_pair(a, b));
                        m--;
                        if(m==0) break;
                    }
                }
                if(m==0) break;
            }
        }
        if(m==0)
        {
            cout<<"Possible\n";
            for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
        }
        else cout<<"Impossible";
    }
}
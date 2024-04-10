#include <bits/stdc++.h>

using namespace std;

const int N=5000+7;
int sol[N], last[N];

int main()
{
        ios::sync_with_stdio(0); cin.tie(0);

        for (int i=1; i<N; i++)
        {
                int want=i, cur=1;
                while (cur<=want)
                {
                        want-=cur;
                        cur+=2;
                        sol[i]++;
                }
                sol[i]+=(want>0);
        }
        int t;
        cin>>t;
        for (int i=1; i<=t; i++)
        {
                int x;
                cin>>x;
                cout<<sol[x]<<"\n";
        }
        return 0;
}
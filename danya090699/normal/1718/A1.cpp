#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int an=n, su=0;
        set <int> se;
        se.insert(su);
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%d", &x);
            if(x)
            {
                su^=x;
                if(se.find(su)!=se.end())
                {
                    se.clear();
                    an--;
                    su=0;
                }
            }
            else
            {
                se.clear();
                an--;
                su=0;
            }
            se.insert(su);
        }
        cout<<an<<"\n";
    }
}
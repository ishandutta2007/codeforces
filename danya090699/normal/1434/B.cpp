#include <bits/stdc++.h>
using namespace std;
const int inf=1e9+10;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int an[n];
    vector <int> p;
    vector <pair <int, int> > st;

    int i=0;
    for(int a=0; a<n*2; a++)
    {
        char sy;
        cin>>sy;
        if(sy=='+')
        {
            p.push_back(i++);
            st.push_back({0, 1});
        }
        else
        {
            int x;
            scanf("%d", &x);
            if(st.size() and x>st.back().first)
            {
                int su=0;
                while(st.size() and st.back().first<x)
                {
                    su+=st.back().second;
                    st.pop_back();
                }
                su--;
                if(su) st.push_back({x, su});

                an[p.back()]=x;
                p.pop_back();
            }
            else
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}
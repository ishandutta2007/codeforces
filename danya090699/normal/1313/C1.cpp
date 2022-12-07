#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    long long va[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        va[a]=0;
    }
    for(int i=0; i<2; i++)
    {
        vector <pair <int, int> > st(1, {0, 0});
        long long su=0;
        for(int a=0; a<n; a++)
        {
            int q=1;
            while(st.back().first>ar[a])
            {
                su-=1ll*st.back().first*st.back().second;
                q+=st.back().second;
                st.pop_back();
            }
            su+=1ll*q*ar[a];
            st.push_back({ar[a], q});
            va[a]+=su;
        }
        reverse(ar, ar+n);
        reverse(va, va+n);
    }
    long long be=0, p;
    for(int a=0; a<n; a++)
    {
        if(va[a]-ar[a]>be) be=va[a]-ar[a], p=a;
    }
    int an[n];
    an[p]=ar[p];
    for(int a=p-1; a>=0; a--) an[a]=min(ar[a], an[a+1]);
    for(int a=p+1; a<n; a++) an[a]=min(ar[a], an[a-1]);
    for(int a=0; a<n; a++) printf("%d ", an[a]);
}
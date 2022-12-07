#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a].first), ar[a].second=a*2+1;
    sort(ar, ar+n, greater <pair <int, int> >());
    vector <int> st;
    for(int a=0; a<n; a++)
    {
        st.push_back(ar[a].second);
        if(a) printf("%d %d\n", ar[a-1].second, ar[a].second);
    }
    for(int a=0; a<n; a++)
    {
        int p=a+ar[a].first-1;
        printf("%d %d\n", st[p], ar[a].second+1);
        if(p+1==st.size()) st.push_back(ar[a].second+1);
    }
}
#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, vector <int> > ma;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ma[ar[a]].push_back(x);
    }
    multiset <int, greater <int> > se;
    long long su=0, an=0;
    int p=0;
    while(se.size() or ma.size())
    {
        if(se.size()==0) p=(*ma.begin()).first;
        if(ma.size() and p==(*ma.begin()).first)
        {
            while((*ma.begin()).second.size())
            {
                se.insert((*ma.begin()).second.back());
                su+=(*ma.begin()).second.back();
                (*ma.begin()).second.pop_back();
            }
            ma.erase(ma.begin());
        }
        su-=(*se.begin());
        se.erase(se.begin());
        an+=su;
        p++;
    }
    cout<<an;
}
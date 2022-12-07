#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int n, m, k;
	cin>>n>>m>>k;
	vector <pair <int, string> > sp, an;
	if(m>1)
    {
        sp.push_back({m-1, "R"});
        sp.push_back({m-1, "L"});
    }
    for(int a=1; a<n; a++)
    {
        sp.push_back({1, "D"});
        if(m>1)
        {
            sp.push_back({m-1, "RUD"});
            sp.push_back({m-1, "L"});
        }
    }
    if(n>1) sp.push_back({n-1, "U"});

	for(int a=0; a<sp.size(); a++)
    {
        if(sp[a].first*sp[a].second.size()<=k)
        {
            an.push_back(sp[a]);
            k-=sp[a].first*sp[a].second.size();
        }
        else
        {
            int q=k/sp[a].second.size(), os=k%sp[a].second.size();
            if(q) an.push_back({q, sp[a].second});
            if(os) an.push_back({1, sp[a].second.substr(0, os)});
            k=0;
        }
    }

    if(k) cout<<"NO";
    else
    {
        cout<<"YES\n"<<an.size()<<"\n";
        for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
    }
}
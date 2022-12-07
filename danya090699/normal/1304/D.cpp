#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        int n;
        string s;
        cin>>n>>s;
        vector <int> sp, mi, ma;
        sp.push_back(1);
        for(int a=0; a<n-1; a++)
        {
            if(s[a]=='<') sp.back()++;
            else sp.push_back(1);
        }
        int q=0;
        for(int a=0; a<sp.size(); a++)
        {
            for(int b=sp[a]-1; b>=0; b--) mi.push_back(n-q-b);
            ma.push_back(sp.size()-a);
            for(int b=1; b<sp[a]; b++) ma.push_back(sp.size()+q-a+b);
            q+=sp[a];
        }
        for(int a=0; a<n; a++) printf("%d ", mi[a]);
        printf("\n");
        for(int a=0; a<n; a++) printf("%d ", ma[a]);
        printf("\n");
    }
}
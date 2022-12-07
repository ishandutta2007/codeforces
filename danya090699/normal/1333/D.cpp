#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, q=0;
    cin>>n>>k;
    string s;
    cin>>s;
    vector <vector <int> > sp;
    while(1)
    {
        vector <int> cu;
        for(int a=0; a+1<n; a++)
        {
            if(s[a]=='R' and s[a+1]=='L')
            {
                swap(s[a], s[a+1]), cu.push_back(a+1);
                q++, a++;
            }
        }
        if(cu.size()) sp.push_back(cu);
        else break;
    }
    if(k<sp.size() or k>q) cout<<-1;
    else
    {
        for(int a=0; a<sp.size(); a++)
        {
            if(q-sp[a].size()<k-1)
            {
                int m=q-(k-1);
                printf("%d", m);
                for(int b=0; b<m; b++) printf(" %d", sp[a][b]);
                printf("\n");
                k--;
                for(int b=m; b<sp[a].size(); b++)
                {
                    printf("1 %d\n", sp[a][b]);
                    k--;
                }
            }
            else
            {

                printf("%d", sp[a].size());
                for(int b=0; b<sp[a].size(); b++) printf(" %d", sp[a][b]);
                printf("\n");
                k--;
            }
            q-=sp[a].size();
        }
    }
}
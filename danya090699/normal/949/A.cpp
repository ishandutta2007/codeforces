#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size();
    vector <int> an[n], nu, ed;
    int q=0, ok=1;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='0')
        {
            if(ed.size()==0)
            {
                ed.push_back(q), q++;
            }
            an[ed.back()].push_back(a+1);
            nu.push_back(ed.back());
            ed.pop_back();
        }
        else
        {
            if(nu.size())
            {
                an[nu.back()].push_back(a+1);
                ed.push_back(nu.back());
                nu.pop_back();
            }
            else ok=0;
        }
    }
    if(ok and ed.size()==0)
    {
        cout<<q<<"\n";
        for(int a=0; a<q; a++)
        {
            printf("%d ", an[a].size());
            for(int b=0; b<an[a].size(); b++) printf("%d ", an[a][b]);
            printf("\n");
        }
    }
    else cout<<-1;
}
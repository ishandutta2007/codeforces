#include <bits/stdc++.h>
using namespace std;
int de(int x, int y){return x/y+(x%y>0);}
int main()
{
    string str;
    cin>>str;
    int n=str.size();
    vector <vector <int> > sp;
    sp.resize(1);
    for(int a=0; a<n; a++) sp[0].push_back(a);

    while(sp.size()<n)
    {
        char s[n];
        int yk=0;
        for(int a=0; a<sp.size(); a++)
        {
            int bl=de(sp[a].size(), 26);
            for(int b=0; b<sp[a].size(); b++) s[yk+b]='a'+b/bl;
        
            yk+=sp[a].size();
        }

        cout<<"? ";
        for(int a=0; a<n; a++) cout<<s[a];
        cout<<"\n";
        for(int a=0; a<n; a++) cin>>s[a];

        vector <vector <int> > nsp;
        for(int a=0; a<sp.size(); a++)
        {
            int bl=de(sp[a].size(), 26), bq=de(sp[a].size(), bl), bl0=nsp.size();
            nsp.resize(nsp.size()+bq);
            for(int b=0; b<sp[a].size(); b++)
            {
                int nu=s[sp[a][b]]-'a';
                nsp[bl0+nu].push_back(sp[a][b]);
            }
        }

        sp.clear();
        for(int a=0; a<nsp.size(); a++) sp.push_back(nsp[a]);
    }
    cout<<"! ";
    for(int a=0; a<n; a++) cout<<str[sp[a][0]];
    cout<<"\n";
}
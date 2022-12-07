#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q=0;
    s+=s;
    vector <int> sp[26];
    for(int a=0; a<n; a++)
    {
        sp[s[a]-'a'].push_back(a);
    }
    for(int a=0; a<26; a++)
    {
        int cu=0;
        for(int b=0; b<n; b++)
        {
            int qq[26];
            for(int c=0; c<26; c++) qq[c]=0;
            for(int c=0; c<sp[a].size(); c++)
            {
                int p=sp[a][c];
                qq[s[p+b]-'a']++;
            }
            int su=0;
            for(int c=0; c<26; c++) if(qq[c]==1) su++;
            cu=max(cu, su);
        }
        q+=cu;
    }
    cout<<fixed<<setprecision(10)<<(q*1.0/n);
}
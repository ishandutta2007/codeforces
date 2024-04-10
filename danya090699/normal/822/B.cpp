//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k=1e9;
    string s, t;
    cin>>n>>m>>s>>t;
    vector <int> po;
    for(int a=0; a<=(m-n); a++)
    {
        int cu=0;
        for(int b=0; b<n; b++) if(s[b]!=t[a+b]) cu++;
        if(cu<k)
        {
            k=cu;
            po.clear();
            for(int b=0; b<n; b++) if(s[b]!=t[a+b]) po.push_back(b+1);
        }
    }
    cout<<k<<"\n";
    for(int a=0; a<k; a++) cout<<po[a]<<" ";
}
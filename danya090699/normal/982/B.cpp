#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    set <pair<int, int> > in;
    set <pair<int, int>, greater <pair <int, int> > > ex;
    for(int a=0; a<n; a++)
    {
        int w;
        cin>>w;
        in.insert(make_pair(w, a+1));
    }
    string s;
    cin>>s;
    for(int a=0; a<n*2; a++)
    {
        if(s[a]=='0')
        {
            pair <int, int> cu=*in.begin();
            in.erase(in.begin());
            cout<<cu.second<<" ";
            ex.insert(cu);
        }
        else
        {
            pair <int, int> cu=*ex.begin();
            ex.erase(ex.begin());
            cout<<cu.second<<" ";
        }
    }
}
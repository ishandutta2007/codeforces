#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    map <char, int> ma;
    int n, an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        ma[s[0]]++;
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int q=(*it).second/2+(*it).second%2;
        an+=q*(q-1)/2;

        q=(*it).second/2;
        if(q) an+=q*(q-1)/2;
    }
    cout<<an;
}
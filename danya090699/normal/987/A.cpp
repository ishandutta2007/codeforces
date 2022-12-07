#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    map <string, string> ma;
    ma["purple"]="Power";
    ma["green"]="Time";
    ma["blue"]="Space";
    ma["orange"]="Soul";
    ma["red"]="Reality";
    ma["yellow"]="Mind";
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        ma.erase(s);
    }
    cout<<ma.size()<<"\n";
    for(auto it=ma.begin(); it!=ma.end(); it++) cout<<(*it).second<<"\n";
}
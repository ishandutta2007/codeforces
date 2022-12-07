#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    string s;
    cin>>n>>s;
    map <string, int> ma;
    for(int a=0; a+1<n; a++) ma[s.substr(a, 2)]++;
    vector <pair <int, string> > ve;
    for(auto it=ma.begin(); it!=ma.end(); it++) ve.push_back(make_pair((*it).second, (*it).first));
    sort(ve.begin(), ve.end());
    cout<<ve.back().second;
}
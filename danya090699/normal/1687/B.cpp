#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    pair <int, int> re[m];
    for(int a=0; a<m; a++)
    {
        string s;
        for(int b=0; b<m; b++) s.push_back('0');
        s[a]='1';
        cout<<"? "<<s<<"\n";
        cin>>re[a].first;
        re[a].second=a;
    }
    sort(re, re+m);
    string an;
    for(int a=0; a<m; a++) an.push_back('0');
    int su=0;
    for(int a=0; a<m; a++)
    {
        an[re[a].second]='1';
        cout<<"? "<<an<<"\n";
        int su2;
        cin>>su2;
        if(su2!=su+re[a].first) an[re[a].second]='0';
        else su+=re[a].first;
    }
    cout<<"! "<<su<<"\n";
}
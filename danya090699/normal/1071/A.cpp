#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int a=1, bad=-1;
    for(a=1; a<=n; a++) n-=a;
    if(n) bad=a-n, a++;
    vector <int> an;
    for(int i=1; i<a; i++) if(i!=bad) an.push_back(i);

    cout<<an.size()<<"\n";
    for(int i=0; i<an.size(); i++) cout<<an[i]<<" ";
    cout<<"\n";

    an.clear();
    if(bad!=-1 and bad<=m) an.push_back(bad), m-=bad;

    for(a; a<=m; a++) an.push_back(a), m-=a;

    cout<<an.size()<<"\n";
    for(int i=0; i<an.size(); i++) cout<<an[i]<<" ";
}
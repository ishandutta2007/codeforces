//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, cu=0;
    cin>>n>>k;
    vector <int> pa[k];
    for(int a=0; a<k; a++) pa[a].push_back(a);
    for(int a=k; a<n-1; a++)
    {
        pa[cu].push_back(a);
        cu=(cu+1)%k;
    }
    cout<<pa[0].size()+pa[1].size()<<"\n";
    for(int a=0; a<k; a++)
    {
        pa[a].push_back(n-1);
        for(int b=0; b<pa[a].size()-1; b++) cout<<pa[a][b]+1<<" "<<pa[a][b+1]+1<<"\n";
    }
}
//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter map <int, int>::iterator
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        ma[x]++;
    }
    if(ma.size()==2)
    {
        iter it=ma.begin();
        int q1=(*it).second, v1=(*it).first;
        it++;
        int q2=(*it).second, v2=(*it).first;
        if(q1==q2)
        {
            cout<<"YES\n"<<v1<<" "<<v2;
        }
        else cout<<"NO";
    }
    else cout<<"NO";
}
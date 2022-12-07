#include <bits/stdc++.h>
using namespace std;
main()
{
    int n;
    cin>>n;
    vector <int> sp;
    int an[n+1];
    for(int a=1; a<=n; a++) sp.push_back(a);
    for(int a=0; a<n-1; a++)
    {
        int i=sp.back();
        sp.pop_back();
        int j=sp.back();
        sp.pop_back();
        cout<<"? "<<i<<" "<<j<<"\n";
        int re1;
        cin>>re1;
        cout<<"? "<<j<<" "<<i<<"\n";
        int re2;
        cin>>re2;
        if(re1<re2) swap(re1, re2), swap(i, j);
        an[i]=re1;
        sp.push_back(j);
    }
    an[sp.back()]=n;
    cout<<"!";
    for(int a=1; a<=n; a++) cout<<" "<<an[a];
    cout<<"\n";
}
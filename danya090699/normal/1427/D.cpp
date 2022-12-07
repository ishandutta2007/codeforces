#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    vector <vector <int> > an;
    for(int a=1; a<n; a++)
    {
        int p;
        for(int b=0; b<n; b++) if(ar[b]==a) p=b;
        an.resize(an.size()+1);
        if(a&1)
        {
            for(int b=1; b<a; b++) an.back().push_back(1);
            an.back().push_back(p+1-(a-1));
            if(p!=n-1) an.back().push_back(n-1-p);
        }
        else
        {
            if(p!=0) an.back().push_back(p);
            an.back().push_back(n-p-(a-1));
            for(int b=1; b<a; b++) an.back().push_back(1);
        }
        if(an.back().size()==1) an.pop_back();
        else
        {
            int ar2[n], yk=0, yk2=n;
            for(int b=0; b<an.back().size(); b++)
            {
                int q=an.back()[b];
                yk2-=q;
                for(int c=0; c<q; c++)
                {
                    ar2[yk2+c]=ar[yk], yk++;
                }
            }
            for(int a=0; a<n; a++) ar[a]=ar2[a];
        }
    }
    if(n%2==0)
    {
        an.resize(an.size()+1);
        for(int a=0; a<n; a++) an.back().push_back(1);
        reverse(ar, ar+n);
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++)
    {
        cout<<an[a].size();
        for(int b=0; b<an[a].size(); b++) cout<<" "<<an[a][b];
        cout<<"\n";
    }
}
#include <bits/stdc++.h>
using namespace std;
main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        set <int> se;
        for(int a=1; a<=n; a++) se.insert(a);
        vector <vector <int> > sp(k);
        for(int a=0; a<k; a++)
        {
            int q;
            cin>>q;
            sp[a].resize(q);
            for(int b=0; b<q; b++)
            {
                cin>>sp[a][b];
                se.erase(sp[a][b]);
            }
        }
        if(se.size())
        {
            sp.resize(k+1);
            for(auto it=se.begin(); it!=se.end(); it++) sp[k].push_back(*it);
        }
        int ma;
        cout<<"? "<<n;
        for(int a=1; a<=n; a++) cout<<" "<<a;
        cout<<"\n";
        cin>>ma;
        int l=0, r=sp.size()-1;
        while(l!=r)
        {
            int mid=(l+r)>>1;
            vector <int> ar;
            for(int a=l; a<=mid; a++)
            {
                ar.insert(ar.end(), sp[a].begin(), sp[a].end());
            }
            cout<<"? "<<ar.size();
            for(int a=0; a<ar.size(); a++) cout<<" "<<ar[a];
            cout<<"\n";
            int x;
            cin>>x;
            if(x==ma) r=mid;
            else l=mid+1;
        }
        vector <int> ar;
        for(int a=0; a<sp.size(); a++)
        {
            if(a!=l) ar.insert(ar.end(), sp[a].begin(), sp[a].end());
        }
        cout<<"? "<<ar.size();
        for(int a=0; a<ar.size(); a++) cout<<" "<<ar[a];
        cout<<"\n";
        int ma2;
        cin>>ma2;
        cout<<"!";
        for(int a=0; a<k; a++)
        {
            if(a==l) cout<<" "<<ma2;
            else cout<<" "<<ma;
        }
        cout<<"\n";
        string ok;
        cin>>ok;
    }
}
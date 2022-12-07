#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int su=0;
        set <pair <int, int>, greater<pair <int, int>>> se;
        for(int a=0; a<n; a++)
        {
            int x;
            scanf("%lld", &x);
            se.insert({x, a});
            su+=x;
        }
        vector <int> fi;
        if(su)
        {
            fi.push_back(1);
            su--;
        }
        if(su)
        {
            fi.push_back(1);
            su--;
        }
        while(su>0)
        {
            int x = fi[fi.size()-2]+fi[fi.size()-1];
            fi.push_back(x);
            su-=x;
        }
        if(su==0)
        {
            int pr=-1;
            while(fi.size())
            {
                int f=fi[fi.size()-1];
                auto it=se.begin();
                if((*it).second==pr) it++;
                if(it==se.end()) break;
                int i=(*it).second, x=(*it).first;
                if(x<f) break;
                x-=f;
                se.erase(it);
                se.insert({x, i});
                pr=i;
                fi.pop_back();
            }
            if(fi.size()) cout<<"NO\n";
            else cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}
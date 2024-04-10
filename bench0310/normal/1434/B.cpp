#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<int,2>> sell;
    string t(2*n,'$');
    vector<int> price(2*n,0);
    vector<int> buy(2*n,0);
    set<int> tm;
    for(int i=0;i<2*n;i++)
    {
        char c;
        cin >> c;
        if(c=='+') tm.insert(i);
        else
        {
            int x;
            cin >> x;
            sell.push_back({x,i});
            buy[i]=x;
        }
        t[i]=c;
    }
    auto out=[]()
    {
        cout << "NO\n";
        exit(0);
    };
    sort(sell.begin(),sell.end());
    for(auto [a,id]:sell)
    {
        auto it=tm.lower_bound(id);
        if(it==tm.begin()) out();
        it--;
        price[(*it)]=a;
        tm.erase(it);
    }
    set<int> s;
    for(int i=0;i<2*n;i++)
    {
        if(t[i]=='+') s.insert(price[i]);
        else
        {
            if((*s.begin())!=buy[i]) out();
            s.erase(s.begin());
        }
    }
    cout << "YES\n";
    for(int i=0;i<2*n;i++) if(price[i]!=0) cout << price[i] << " ";
    cout << "\n";
    return 0;
}
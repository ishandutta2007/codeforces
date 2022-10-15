#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int get(char ch)
{
        if(ch=='?')
        {
                return get('z')+1;
        }
        else
        {
                return ch-'a';
        }
}

vector<int>a[30],b[30];

vector<pair<int,int>>res;

void addup(int i,int j)
{
        while(a[i].size()>=1 && b[j].size()>=1)
        {
                res.push_back({a[i].back(),b[j].back()});
                a[i].pop_back();
                b[j].pop_back();
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
                a[get(s[i])].push_back(i+1);
        }
        cin>>s;
        for(int i=0;i<n;i++)
        {
                b[get(s[i])].push_back(i+1);
        }
        for(int i=0;i<26;i++)
        {
                addup(i,i);
        }
        for(int i=0;i<26;i++)
        {
                addup(26,i);
                addup(i,26);
        }
        addup(26,26);
        cout<<res.size()<<"\n";
        for(auto &it:res)
        {
                cout<<it.first<<" "<<it.second<<"\n";
        }
        return 0;
}
/**

**/
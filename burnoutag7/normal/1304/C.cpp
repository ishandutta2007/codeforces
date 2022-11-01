#include<bits/stdc++.h>
using namespace std;


int q,n,m,top,bot,cur;
vector<pair<int,pair<int,int> > > v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n>>m;
        v.resize(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first>>v[i].second.first>>v[i].second.second;
        }
        sort(v.begin(),v.end());
        top=bot=m;cur=0;
        bool f=true;
        for(int i=0;i<n;i++){
            top+=v[i].first-cur;
            bot-=v[i].first-cur;
            top=min(top,v[i].second.second);
            bot=max(bot,v[i].second.first);
            if(top<v[i].second.first||bot>v[i].second.second){
                f=false;
                break;
            }
            cur=v[i].first;
        }
        if(f)cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}
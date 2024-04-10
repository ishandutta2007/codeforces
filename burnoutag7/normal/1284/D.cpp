#include<bits/stdc++.h>
using namespace std;

int l[100005][2],r[100005][2],n;
vector<pair<int,pair<int,int> > > v;
multiset<int> ls,rs;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i][0]>>r[i][0];
        cin>>l[i][1]>>r[i][1];
    }
    for(int t=0;t<2;t++){
        v.clear();ls.clear();rs.clear();
        for(int i=1;i<=n;i++){
            v.push_back(make_pair(l[i][t],make_pair(0,i)));
            v.push_back(make_pair(r[i][t],make_pair(1,i)));
        }
        sort(v.begin(),v.end());
        int ltp=v.front().second.first,lt=v.front().first;
        for(int i=0;i<v.size();i++){
            if(v[i].first!=lt||v[i].second.first!=ltp){
                if(!ls.empty()&&*ls.rbegin()>*rs.begin()){
                    cout<<"NO"<<endl;
                    return 0;
                }
            }
            pair<int,pair<int,int> > &p=v[i];
            lt=p.first;
            ltp=p.second.first;
            int tp=p.second.first;
            int id=p.second.second;
            if(tp==0){
                ls.insert(l[id][t^1]);
                rs.insert(r[id][t^1]);
            }else{
                ls.erase(ls.find(l[id][t^1]));
                rs.erase(rs.find(r[id][t^1]));
            }
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
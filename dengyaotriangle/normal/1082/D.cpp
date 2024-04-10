#include<bits/stdc++.h>
using namespace std;
    
const int maxn=505;

int deg[maxn];
int n;
vector<int> v1,v2;
vector<pair<int,int> > ans;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>deg[i];
    for(int i=1;i<=n;i++){
        if(deg[i]==1) v1.push_back(i);
        else v2.push_back(i);
    }
    for(int i=1;i<v2.size();i++){
        ans.push_back(make_pair(v2[i],v2[i-1]));
        deg[v2[i]]--;deg[v2[i-1]]--;
    }
    int cans=v2.size()-1;
    bool cn1=1,cn2=1;
    if(v2.size()==0){
        cout<<"NO";
        return 0;
    }
    for(int i=0;i<v1.size();i++){
        if(cn1&&deg[v2[0]]){
            ans.push_back(make_pair(v1[i],v2[0]));
            cans++;
            deg[v2[0]]--;
            cn1=0;
            continue;
        }
        if(cn2&&deg[v2[v2.size()-1]]){
            ans.push_back(make_pair(v1[i],v2[v2.size()-1]));
            cans++;
            deg[v2[v2.size()-1]]--;
            cn2=0;
            continue;
        }
        bool fd=0;
        for(int j=0;j<v2.size();j++){
            if(deg[v2[j]]){
                ans.push_back(make_pair(v1[i],v2[j]));
                deg[v2[j]]--;
                fd=1;
                break;
            }
        }
        if(!fd){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES "<<cans<<'\n';
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++) cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    return 0;
}
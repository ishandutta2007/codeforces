#include<bits/stdc++.h>
using namespace std;

int t,n;
string s;
int px;
int py;
map<pair<int,int>,set<int> > mp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        cin>>s;
        px=py=0;
        mp.clear();
        mp[make_pair(0,0)].insert(-1);
        for(int i=0;i<n;i++){
            px=px+(s[i]=='R')-(s[i]=='L');
            py=py+(s[i]=='U')-(s[i]=='D');
            mp[make_pair(px,py)].insert(i);
        }
        int ansl,ansr,ans=1e9;
        for(map<pair<int,int>,set<int> >::iterator it=mp.begin();it!=mp.end();it++){
            if(it->second.size()>1){
                vector<int> v;
                for(set<int>::iterator i=it->second.begin();i!=it->second.end();i++){
                    v.push_back(*i);
                }
                for(int l=0,r=0;l<v.size();l++){
                    while(r<v.size()&&v[r]-v[l]<=0)r++;
                    if(r==v.size())break;
                    if(v[r]-v[l]<ans){
                        ans=v[r]-v[l];
                        ansl=v[l]+2;
                        ansr=v[r]+1;
                    }
                }
            }
        }
        if(ans==1e9){
            cout<<-1<<endl;
        }else{
            cout<<ansl<<' '<<ansr<<endl;
        }
    }

    return 0;
}
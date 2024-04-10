#include<bits/stdc++.h>
using namespace std;

int T,n;
string s,t;
vector<pair<int,int>> out;
int cnt[26];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>s>>t;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']^=1;
            cnt[t[i]-'a']^=1;
        }
        for(int i=1;i<26;i++){
            cnt[0]|=cnt[i];
        }
        if(cnt[0]){
            cout<<"No"<<endl;
            continue;
        }
        cout<<"Yes"<<endl;
        out.clear();
        for(int i=0;i<n;i++){
            if(s[i]==t[i])continue;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    out.push_back(make_pair(j+1,i+1));
                    swap(s[j],t[i]);
                    break;
                }
                if(s[i]==t[j]){
                    out.push_back(make_pair(j+1,j+1));
                    swap(s[j],t[j]);
                    out.push_back(make_pair(j+1,i+1));
                    swap(s[j],t[i]);
                    break;
                }
            }
        }
        assert(s==t);
        cout<<out.size()<<endl;
        for(int i=0;i<out.size();i++){
            cout<<out[i].first<<' '<<out[i].second<<endl;
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int t,n;
map<string,int> mp;
vector<string> v;
string s[10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        mp.clear();
        v.clear();
        for(int i=0;i<n;i++){
            cin>>s[i];
            mp[s[i]]++;
        }
        cout<<n-mp.size()<<endl;
        for(int i=0;i<n;i++){
            if(mp[s[i]]>1){
                mp[s[i]]--;
                for(char j='0';j<='9';j++){
                    if(mp[s[i].substr(0,3)+j]==0){
                        mp[s[i].substr(0,3)+j]++;
                        v.push_back(s[i].substr(0,3)+j);
                        break;
                    }
                }
            }else{
                v.push_back(s[i]);
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
    }

    return 0;
}
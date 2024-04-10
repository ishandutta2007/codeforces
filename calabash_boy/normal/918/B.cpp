#include<bits/stdc++.h>
using namespace std;
const int maxn =1000+100;
map<string,string> mp;
int n,m;
int main(){
    cin>>n>>m;
    for (int i=0;i<n;i++){
        string s1,s2;
        cin>>s1>>s2;
        s2+=';';
        mp.insert(make_pair(s2,s1));
    }
    for (int i=0;i<m;i++){
        string s1,s2;
        cin>>s1>>s2;
        cout<<s1<<" "<<s2<<" #"<<mp[s2]<<endl;
    }
    return 0;
}
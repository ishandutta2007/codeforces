#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int> Z(vector<pair<ll,char>> p,vector<pair<ll,char>> t){
    vector<pair<ll,char>> s=p;
    s.push_back(make_pair(1,'$'));
    for(pair<ll,char>&cur:t)s.push_back(cur);
    int len=s.size(),l=0,r=0;
    vector<int> z(len),res;
    z[0]=len;
    for(int i=1;i<len;i++){
        if(i>r){
            l=i;r=i-1;
            while(s[r+1]==s[z[i]])r++,z[i]++;
        }else{
            if(i+z[i-l]<=r){
                z[i]=z[i-l];
            }else{
                l=i;
                z[i]=r-i+1;
                while(s[r+1]==s[z[i]])r++,z[i]++;
            }
        }
        if(i>p.size()&&z[i]>=p.size())res.push_back(i-p.size()-1);
    }
    return res;
}

int n,m;
vector<pair<ll,char>> p,t;
pair<ll,char> head,tail;

void read(){
    cin>>n>>m;
    pair<ll,char> cur;char c;
    for(int i=0;i<n;i++){
        cin>>cur.first>>c>>cur.second;
        if(t.empty()||t.back().second!=cur.second)t.push_back(cur);
        else t.back().first+=cur.first;
    }
    n=t.size();
    for(int i=0;i<m;i++){
        cin>>cur.first>>c>>cur.second;
        if(p.empty()||p.back().second!=cur.second)p.push_back(cur);
        else p.back().first+=cur.first;
    }
    m=p.size();
    head=p.front();
    p.erase(p.begin());
    if(m==1){
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(t[i].second==head.second){
                cnt+=max(0ll,t[i].first-head.first+1);
            }
        }
        cout<<cnt<<endl;
        exit(0);
    }
    tail=p.back();
    p.pop_back();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    read();
    vector<int> z=Z(p,t);
    int ans=0;
    for(int &i:z){
        if(i&&i+m-2<n&&
        t[i-1].first>=head.first&&t[i-1].second==head.second&&
        t[i+m-2].first>=tail.first&&t[i+m-2].second==tail.second){
            ans++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

set<pair<int,bool>> s1,s2;

long long ans=0;
int pt;
void ins(int d,bool t){
    if(s1.empty()||d>s1.rbegin()->first){
        s2.insert({d,t});ans+=d*2;
        pt+=t;
    }else{
        s1.insert({d,t});ans+=d;
    }
}
void del(int d,bool t){
    d=-d;
    if(s1.find({d,t})!=s1.end()){
        s1.erase({d,t});
        ans-=d;
    }else{
        s2.erase({d,t});
        ans-=d*2;
        pt-=t;
    }
}
int cnt=0;

void adjust(){
    while(s2.size()<cnt){
        auto it =s1.end();it--;
        int u=it->first;pt+=it->second;
        s2.insert(*it);ans+=u;
        s1.erase(it);
    }
    while(s2.size()>cnt){
        int u=s2.begin()->first;pt-=s2.begin()->second;
        s1.insert(*s2.begin());ans-=u;
        s2.erase(s2.begin());
    }
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        int t,d;
        cin>>t>>d;
        if(t==0){
            if(d>0){
                ins(d,t);
            }else{
                del(d,t);
            }
        }else if(t==1){
            if(d>0){
                ins(d,t);
                cnt++;
            }else{
                del(d,t);
                cnt--;
            }
        }
        adjust();
        long long tans=ans;
        if(!s2.empty()&&cnt==pt){
            tans-=s2.begin()->first;
            if(!s1.empty())tans+=s1.rbegin()->first;
        }
        cout<<tans<<'\n';
    }
    return 0;
}
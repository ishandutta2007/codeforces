#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100006;

int n;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        set<int> rp,s;
        for(int i=1;i<=n;i++)s.insert(i);
        for(int i=1;i<n;i++){
            if(__gcd(a[i],a[i+1])==1)rp.insert(i+1);
        }
        if(__gcd(a[n],a[1])==1)rp.insert(1);
        int i=2;
        vector<int> ans;
        while(!rp.empty()){
            auto t=rp.lower_bound(i);
            if(t==rp.end()){
                t=rp.begin();
            }
            int u=*t;
            ans.push_back(u);
            rp.erase(t);
            auto it1=s.lower_bound(u),it2=it1,it3=it1;
            if(it1==s.begin()){it2=s.end();}
            --it2;
            ++it3;
            if(it3==s.end()){it3=s.begin();}
            int v3=*it3,v2=*it2;
            if(__gcd(a[*it2],a[*it3])!=1)rp.erase(*it3);
            else rp.insert(*it3);
            //cerr<<*it2<<' '<<*it3<<endl;
            s.erase(it1);
            if(!s.count(v3)||!s.count(v2))rp.erase(v3);
            i=v3+1;if(i>n)i=1;
        }
        cout<<ans.size()<<' ';
        for(int u:ans)cout<<u<<' ';
        cout<<'\n';
    }
    return 0;
}
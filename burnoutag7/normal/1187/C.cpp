#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> > q[2];
vector<pair<int,int> > v;
int ans[1005];

int func(int x){
    int l=0,r=v.size()-1,m,ans;
    while(l<=r){
        m=(l+r)/2;if(m<0)return -1;
        if(v[m].first<=x){
            ans=m;
            l=m+1;
        }else{
            r=m-1;
        }
    }
    if(v[ans].second>=x)return ans;
    else return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int tp,a,b;
        cin>>tp>>a>>b;
        q[tp].push_back(make_pair(a,b));
    }
    sort(q[1].begin(),q[1].end());
    v.push_back(make_pair(1,1));
    for(int i=0;i<q[1].size();i++){
        int l=q[1][i].first,r=q[1][i].second;
        int pos=func(l);
        if(pos==-1){
            v.push_back(make_pair(l,r));
        }else{
            v[pos].second=max(v[pos].second,r);
        }
    }
    for(int i=0;i<q[0].size();i++){
        int l=q[0][i].first,r=q[0][i].second;
        int pos=func(l);
        if(pos!=-1){
            if(v[pos].second>=r){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    int pos=0,cnt=500000000;
    for(int i=1;i<=n;i++){
        int pos=func(i);
        if(pos==-1){
            cnt--;
            ans[i]=cnt;
        }else{
            if(v[pos].first==i){
                cnt--;
                ans[i]=cnt;
            }else{
                cnt++;
                ans[i]=cnt;
            }
        }
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}
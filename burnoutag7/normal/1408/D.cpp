#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[2005],b[2005],c[2005],d[2005],h[1000005];
vector<pair<int,int>> pd;
int val[2005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    for(int i=1;i<=m;i++){
        cin>>c[i]>>d[i];
        h[c[i]]=d[i]+1;
    }
    for(int i=999999;i>=0;i--)h[i]=max(h[i+1],h[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(c[j]>=a[i])pd.emplace_back(c[j]-a[i]+1,i);
        }
    sort(pd.begin(),pd.end());
    multiset<int> s;
    for(int i=1;i<=n;i++){
        s.insert(val[i]=h[a[i]]-b[i]);
    }
    int ans=1e9;
    for(int i=0,j=0;i<=1000000;i++){
        while(j<pd.size()&&pd[j].first==i){
            int k=pd[j].second;
            s.erase(s.find(val[k]));
            if(a[k]+i<=1000000)s.insert(val[k]=h[a[k]+i]-b[k]);
            else s.insert(val[k]=0);
            j++;
        }
        ans=min(ans,i+max(0,*s.rbegin()));
    }
    cout<<ans<<endl;

    return 0;
}
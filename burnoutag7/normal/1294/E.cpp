#include<bits/stdc++.h>
using namespace std;

int n,m,ans;
vector<int> a[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t;cin>>t;t--;
            a[j].push_back(t);
        }
    }
    swap(n,m);
    for(int i=0;i<n;i++){
        map<int,int> mp;
        for(int j=0;j<m;j++){
            if(a[i][j]%n!=i||a[i][j]/n>=m)continue;
            mp[(j+m-a[i][j]/n)%m]++;//cerr<<j<<' '<<(j+m-(a[i][j]-1)/n)%m<<endl;
        }
        int res=m;
        for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
            res=min(res,it->first+m-it->second);
        }
        ans+=res;
        //cerr<<res<<endl;
    }
    cout<<ans<<endl;

    return 0;
}
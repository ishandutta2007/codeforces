#include <bits/stdc++.h>

using namespace std;


const long long N=200000;
long long  n;
vector<long long>v[N+5],v2[N+5];
long long sum[N+5];

map<long long,long long>mp; /// mp[sum] -> cnt

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int l;
        cin>>l;
        for(int j=1;j<=l;j++){
            int x;
            cin>>x;
            sum[i]+=x;
            v[i].push_back(x);
            v2[i].push_back(x);
        }
        sort(v[i].begin(),v[i].end());
    }
    for(int i=1;i<=n;i++){
        mp[sum[i]-v[i][0]]++;
        for(int j=1;j<v[i].size();j++){
            if(v[i][j]!=v[i][j-1]){
                mp[sum[i]-v[i][j]]++;
            }
        }
    }
    long long val=0;
    bool gasit=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(mp[sum[i]-v[i][j]]>=2){
                gasit=1;
                val=sum[i]-v[i][j];
                break;
            }
        }
        if(gasit==1)
            break;
    }
    if(gasit==0){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<v[i].size();j++){
            if(sum[i]-v[i][j]==val){
                cnt++;
                for(int k=0;k<v2[i].size();k++){
                    if(v2[i][k]==v[i][j]){
                        cout<<i<<" "<<k+1<<"\n";
                        break;
                    }
                }
                if(cnt==2){
                    return 0;
                }
                break;
            }
        }
    }
    return 0;
}
/**
**/
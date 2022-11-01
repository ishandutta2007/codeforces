#include<bits/stdc++.h>
using namespace std;

int n,a[200005],m;
vector<int> vx,b[200005];

void mian(){
    cin>>n;
    vx.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vx.emplace_back(a[i]);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    m=vx.size();
    for(int i=1;i<=m;i++)b[i].clear();
    for(int i=1;i<=n;i++){
        a[i]=upper_bound(vx.begin(),vx.end(),a[i])-vx.begin();
        b[a[i]].emplace_back(i);
    }
    int ans=0;
    for(int i=1,j;i<=m;i++){
        j=i;
        int sum=b[i].size();
        while(j<m&&b[j+1].front()>b[j].back()){
            sum+=b[++j].size();
        }
        if(i>1)for(int x:b[i-1]){
            sum+=x<b[i].front();
        }
        if(j<m)for(int x:b[j+1]){
            sum+=x>b[j].back();
        }
        i=j;
        ans=max(ans,sum);
    }
    for(int i=1;i<m;i++){
        for(int j=0,k=0;j<=b[i].size();j++){
            if(j)while(k<b[i+1].size()&&b[i+1][k]<b[i][j-1])k++;
            ans=max(ans,j+(int)b[i+1].size()-k);
        }
    }
    cout<<n-ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
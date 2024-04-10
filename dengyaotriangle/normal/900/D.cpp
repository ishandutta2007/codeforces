#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int mdn=1000000007;

inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int x,y;
int main(){
    cin>>x>>y;if(y%x){cout<<0;return 0;}
    y/=x;
    vector<int> d;
    for(int i=1;i*i<=y;i++){
        if(y%i==0){
            d.push_back(i);
            if(i*i!=y)d.push_back(y/i);
        }
    }
    sort(d.begin(),d.end());
    vector<int> ans(d.size());
    for(int i=ans.size()-1;i>=0;i--){
        ans[i]=qpw(2,y/d[i]-1);
        for(int j=i+1;j<ans.size();j++){
            if(d[j]%d[i]==0){
                ans[i]-=ans[j];ans[i]+=ans[i]<0?mdn:0;
            }
        }
    }
    cout<<ans[0];
    return 0;
}
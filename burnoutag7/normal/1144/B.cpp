#include<bits/stdc++.h>
using namespace std;

int n;
int t,ce,co;
vector<int> ve,vo;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int clo=n;
    while(clo--){
        cin>>t;
        if(t&1){
            co++;
            vo.push_back(t);
        }else{
            ce++;
            ve.push_back(t);
        }
    }
    if(co==ce+1||co+1==ce||ce==co){
        cout<<'0'<<endl;
        return 0;
    }
    sort(ve.begin(),ve.end());
    sort(vo.begin(),vo.end());
    int ans=0;
    if(co>ce){
        for(int i=0;i<co-ce-1;i++){
            ans+=vo[i];
        }
    }else{
        for(int i=0;i<ce-co-1;i++){
            ans+=ve[i];
        }
    }
    cout<<ans<<endl;

    return 0;
}
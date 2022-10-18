#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    if(k==0){
        vector<int> v(n);for(int i=0;i<n;i++)cin>>v[i];
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=0;i<n;i++)ans+=i*(long long)v[i];
        cout<<ans;return 0;
    }
    vector<int> ne,po;
    for(int i=0;i<n;i++){
        int v;cin>>v;
        if(v<0)ne.push_back(v);
        else po.push_back(v);
    }
    sort(ne.begin(),ne.end());
    sort(po.begin(),po.end());
    long long sm=accumulate(po.begin(),po.end(),0ll),f0=0;
    for(int i=0;i<(int)po.size();i++)f0+=po[i]*(long long)i;
    for(int i=0;i<(int)ne.size();i++)f0+=ne[i]*(long long)(i/k);
    long long ans=f0;
    int pt=(int)ne.size()-1;
    long long uval=0,usum=0,uans=0;
    int cof=(int)ne.size()==0?-1:((int)(ne.size())-1)/(k+1);
    vector<long long> pfx(ne.size());
    for(int i=(int)ne.size()-1;i>=0;i--){
        pfx[i]=ne[i];
        if(i+k<(int)ne.size())pfx[i]+=pfx[i+k];
    }
    for(int tv=(int)po.size()+1;tv<=n;tv++){
        f0+=sm;
        int dt=tv-po.size();
        if((k+1)*(long long)dt-1>=(int)ne.size()){
            while(pt>=0&&(int)(ne.size())-1-pt+cof+1<dt){
                if(pt%(k+1)==0)cof--;
                f0-=ne[pt]*(long long)(pt/(k+1));
                uval+=usum;
                usum+=ne[pt];
                uans=uval+usum*(cof+1);
                pt--;
            }
            if(pt<0)break;
        }else{
            f0-=pfx[(k+1)*dt-1];
        }
        ans=max(ans,f0+uans);
    }
    cout<<ans;
    return 0;
}
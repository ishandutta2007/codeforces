#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100;
unsigned long long  binom[maxn][maxn];

vector<int> hsh(long long n){
    vector<int> vec;
    for(int i=2;;i++){
        if(n==0)break;
        vec.push_back(n%i);
        n/=i;
    }
    return vec;
}
int main(){
    for(int i=0;i<maxn;i++){
        binom[i][0]=1;
        for(int j=1;j<=i;j++){
            binom[i][j]=binom[i-1][j]+binom[i-1][j-1];
        }
    }
    int t;
    ios::sync_with_stdio(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        long long n;cin>>n;
        //cin>>n;
        vector<int> vec=hsh(n);
        sort(vec.begin(),vec.end(),greater<int>());
        vector<pair<int,int> > pr;
        int lp=0;
        for(int i=1;i<=vec.size();i++){
            if(i==vec.size()||vec[i]!=vec[i-1]){
                pr.push_back(make_pair(i-lp,vec[i-1]));
                lp=i;
            }
        }
        unsigned long long ans=1;
        int sm=0;
        for(int i=0;i<pr.size();i++){
            //cerr<<pr[i].first<<','<<pr[i].second<<',';
            int cnt=vec.size()+1-pr[i].second-sm;
            if(pr[i].second==0)cnt=vec.size()-sm;
            //cerr<<cnt<<';';
            ans*=binom[cnt][pr[i].first];
            sm+=pr[i].first;
        }
        if(pr[pr.size()-1].second==0){
            unsigned long long  oth=1;
            int sm=1;
            for(int i=0;i<pr.size();i++){
                int cnt=vec.size()+1-pr[i].second-sm;
                if(pr[i].second==0)cnt=vec.size()-sm;
                int cn2=pr[i].first;
                if(pr[i].second==0)cn2--;
                oth*=binom[cnt][cn2];
                sm+=cn2;
            }
            ans-=oth;
        }

        // 4 3 3 2 0 0 0 0
        // 8 7 6 5 4 3 2 1
        // 5*10*4*
        cout<<(ans-1)<<'\n';
    }
    return 0;
}
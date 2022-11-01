#include<bits/stdc++.h>
using namespace std;

int n,r;
vector<pair<int,int> > p,np;

bool cmp(pair<int,int> x,pair<int,int> y){
    int xx=x.first+x.second;
    int yy=y.first+y.second;
    return xx>yy;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>r;
    for(int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(b>=0){
            p.push_back(make_pair(a,b));
        }else{
            np.push_back(make_pair(max(a,-b),b));
        }
    }
    sort(p.begin(),p.end());
    for(int i=0;i<p.size();i++){
        if(r<p[i].first){
            cout<<"NO"<<endl;
            return 0;
        }else{
            r+=p[i].second;
        }
    }
    sort(np.begin(),np.end(),cmp);
    for(int i=0;i<np.size();i++){
        if(r<np[i].first){
            cout<<"NO"<<endl;
            return 0;
        }else{
            r+=np[i].second;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}
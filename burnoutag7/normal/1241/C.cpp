#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(int a,int b){
    return a>b;
}

int n,q;
int p[200005];
int w[200005];
int x,a,y,b;
ll k;

bool check(int fir){
    vector<int> v;
    for(int i=0;i<fir;i++){
        if(w[i])v.push_back(w[i]);
    }
    sort(v.begin(),v.end(),cmp);
    ll res=0;
    for(int i=0;i<v.size();i++){
        res+=p[i]*v[i];
    }
    return res>=k;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>p[i];p[i]/=100;
        }
        sort(p,p+n,cmp);
        cin>>x>>a>>y>>b;
        for(int i=0;i<n;i++){
            w[i]=0;
            if((i+1)%a==0)w[i]+=x;
            if((i+1)%b==0)w[i]+=y;
        }
        cin>>k;
        int l=1,r=n,m,ans=-1;
        while(l<=r){
            m=(l+r)>>1;
            if(check(m)){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
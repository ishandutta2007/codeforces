#include<bits/stdc++.h>
using namespace std;

const int B=50;
const int V=1e5;
typedef long long ll;

template<typename T> int get(const vector<T> &v){
    int ans=0;
    for(int i=0,cur=0;i<v.size();i++){
        cur++;
        if(i+1==v.size()||v[i]!=v[i+1]){
            ans=max(ans,cur);
            cur=0;
        }
    }
    return ans;
}

int n,a[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int j=-B;j<=B;j++){
        static vector<ll> v;
        v.clear();
        for(int i=0;i<n;i++){
            v.emplace_back(a[i]-(ll)i*j);
        }
        sort(v.begin(),v.end());
        ans=max(ans,get(v));
    }
    for(int i=0;i<n;i++){
        static vector<int> v;
        v.clear();
        for(int j=i+1;j<n&&(a[i]+(j-i)*(B+1)<=V||a[i]-(j-i)*(B+1)>=1);j++){
            if((a[j]-a[i])%(j-i)==0){
                int d=(a[j]-a[i])/(j-i);
                if(abs(d)>B){
                    v.emplace_back(d);
                }
            }
        }
        sort(v.begin(),v.end());
        ans=max(ans,1+get(v));
    }
    cout<<n-ans<<'\n';

    return 0;
}
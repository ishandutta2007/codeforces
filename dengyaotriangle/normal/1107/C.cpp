#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,k;
int d[maxn];
char c[maxn];

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>d[i];
    cin>>(c+1);
    vector<int> v;
    v.push_back(d[1]);
    long long ans=0;
    for(int i=2;i<=n+1;i++){
        if(c[i]!=c[i-1]||i>n){
            sort(v.begin(),v.end(),greater<int>());
            for(int j=0;j<min(k,(int)v.size());j++){
                ans+=v[j];
            }
            v.clear();v.push_back(d[i]);
        }else{
            v.push_back(d[i]);
        }
    }
    cout<<ans;
    return 0;
}
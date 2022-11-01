#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int l[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    ll sum=0;
    for(int i=1;i<=m;i++){
        cin>>l[i];
        sum+=l[i];
    }
    if(sum<n){
        cout<<-1<<endl;
        return 0;
    }
    int lft=n;
    vector<int> v;
    for(int i=m;i>=1;i--){
        if(i-1+l[i]>n){
            cout<<-1<<endl;
            return 0;
        }
        if(lft>i-1+l[i]){
            v.push_back(lft-l[i]+1);
            lft-=l[i];
        }else{
            v.push_back(i);
            lft=i-1;
        }
    }
    reverse(v.begin(),v.end());
    for(int &x:v)cout<<x<<' ';
    cout<<endl;

    return 0;
}
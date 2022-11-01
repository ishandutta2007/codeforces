#include<bits/stdc++.h>
using namespace std;

int n,a[505];
vector<pair<int,pair<int,int>>> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            v.emplace_back(abs(a[i]-a[j]),a[i]>a[j]?make_pair(i,j):make_pair(j,i));
        }
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(pair<int,pair<int,int>> &p:v){
        cout<<"? "<<p.second.first<<' '<<p.second.second<<endl;
        string s;
        cin>>s;
        if(s=="Yes"){
            cout<<"! "<<p.second.first<<' '<<p.second.second;
            return 0;
        }
    }
    cout<<"! 0 0";

    return 0;
}
#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=105;

multiset<int> a;

int main(){
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        a.insert(t);
    }
    int ans=0;
    while(!a.empty()){
        int s=(*a.begin());
        for(int i=s;i<=100;i+=s){
            a.erase(i);
        }
        ans++;
    }
    cout<<ans;
    return 0;
}
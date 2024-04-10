#include<bits/stdc++.h>
using namespace std;

int T,n,s,k;
set<int> a;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n>>s>>k;
        a.clear();
        while(k--){
            int t;
            cin>>t;
            a.insert(t);
        }
        for(int i=0;;i++){
            if((s-i>=1&&a.find(s-i)==a.end())||(s+i<=n&&a.find(s+i)==a.end())){
                cout<<i<<endl;
                break;
            }
        }
    }

    return 0;
}
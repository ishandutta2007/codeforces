#include<bits/stdc++.h>
using namespace std;

int t,n;
pair<int,int> a[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].first>>a[i].second;
        }
        sort(a+1,a+1+n);
        bool f=false;
        for(int i=2;i<=n;i++){
            if(a[i].second<a[i-1].second){
                f=true;
                break;
            }
        }
        if(f){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++){
            for(int j=0;j<a[i].first-a[i-1].first;j++)cout<<'R';
            for(int j=0;j<a[i].second-a[i-1].second;j++)cout<<'U';
        }
        cout<<endl;
    }

    return 0;
}
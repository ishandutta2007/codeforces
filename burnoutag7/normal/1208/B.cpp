#include<bits/stdc++.h>
using namespace std;

int n;
int a[2005];
set<int> s;
int ans,l,r;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ans=n;
    for(int i=0;i<=n;i++){
        if(s.find(a[i])!=s.end()){
            break;
        }
        s.insert(a[i]);
        set<int> t;
        for(int j=n;j>=1;j--){
            if(s.find(a[j])!=s.end()||t.find(a[j])!=t.end()){
                ans=min(ans,j-i);
                break;
            }
            t.insert(a[j]);
        }
    }
    cout<<ans<<endl;

    return 0;
}
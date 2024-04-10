#include<bits/stdc++.h>
using namespace std;

int T,n,a[300005];
stack<int> t;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        while(!t.empty())t.pop();
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++){
            int cur=a[i];
            while(!t.empty()&&a[i]>t.top()){
                cur=t.top();
                t.pop();
            }
            t.push(cur);
        }
        cout<<(t.size()==1?"YES\n":"NO\n");
    }

    return 0;
}
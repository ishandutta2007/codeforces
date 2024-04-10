#include<bits/stdc++.h>
using namespace std;

int n,a[5005],f[5005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        stack<int> t;
        int ans=0;
        for(int j=i;j>=1;j--){
            if(a[j]==0){
                if(t.empty()||t.top()<0)t.emplace(-j);
                else{
                    ans+=t.top()-j;
                    t.pop();
                }
            }else{
                if(t.empty()||t.top()>0)t.emplace(j);
                else{
                    ans+=-j-t.top();
                    t.pop();
                }
            }
            if(t.empty()||t.top()<0)f[i]=min(f[i],f[j-1]+ans);
        }
    }
    cout<<f[n];

    return 0;
}
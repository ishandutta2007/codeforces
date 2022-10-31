#include <bits/stdc++.h>
using namespace std;
long long n;
long long prost[1000001];
vector<int> ans;
int main(){
    cin>>n;
    for (int i=2;i<=n;++i){
        if (prost[i]==0){
            for (int last=1;last*i<=n;last*=i)
                ans.push_back(last*i);
            for (int j=1;j*i<=n;++j)
                prost[j*i]=1;
        }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}
#include<bits/stdc++.h>
using namespace std;

int t,n;
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        for(int i=2;i*i<=n;i++){
            while(n%i==0){
                n/=i;
                v.push_back(i);
            }
        }
        if(n>1)v.push_back(n);
        if(v.size()<3){
            cout<<"NO"<<endl;
            continue;
        }
        vector<int> ans;
        set<int> t;
        int tmp=1;
        for(int i=0;i<v.size();i++){
            tmp*=v[i];
            if(t.find(tmp)==t.end()){
                ans.push_back(tmp);
                t.insert(tmp);
                tmp=1;
            }
        }
        ans[ans.size()-1]*=tmp;
        if(ans.size()<3){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        cout<<ans[0]<<' '<<ans[1]<<' ';
        tmp=ans[2];
        for(int i=3;i<ans.size();i++){
            tmp*=ans[i];
        }
        cout<<tmp<<endl;
    }

    return 0;
}
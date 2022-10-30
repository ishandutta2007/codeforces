#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
vector<int> t;
int n,k;
int main(){
    cin>>n>>k;
    for (int i=1;i<=n;i++){
        int mask = 0;
        for (int j=0;j<k;j++){
            int bit;
            cin>>bit;
            mask += bit * (1<<j);
        }
        t.push_back(mask);
    }
    sort(t.begin(),t.end());
    t.erase(unique(t.begin(), t.end()),t.end());
    for (auto m1 : t)for (auto m2 : t){
        if (m1 & m2)continue;
        else{
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}
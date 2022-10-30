#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
 
int main(){
 
    int n;
    vector<int> num;
    cin>>n;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        num.push_back(x);
    }
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    int ans = 0;
    for (int i=0;i<num.size();i++){
        bool succ = 1;
        for (int j=0;j<i;j++){
            if (num[i] % num[j] == 0)succ = 0;
        }
        ans += succ;
    }
    cout<<ans<<endl;
    return 0;
}
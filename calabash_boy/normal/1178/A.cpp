#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(0);
    int sum = 0;
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
        sum += x;
    }
    vector<int> ans(0);
    int sum2 = vec[0];
    ans.push_back(0);
    for (int i=1;i<n;i++){
        if(vec[i] * 2 <= vec[0]){
            ans.push_back(i);
            sum2 += vec[i];
        }
    }
    if (sum2 * 2 > sum){
        cout<<ans.size() << endl;
        for (int x : ans){
            cout<<x + 1 <<" ";
        }
        cout<<endl;
    }else{
        cout<<0<<endl;
    }
    return 0;
}
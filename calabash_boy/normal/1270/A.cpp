#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int main(){
    int T;
    cin>>T;
    while (T--){
        int n;
        int k1,k2;
        cin>>n>>k1>>k2;
        vector<int> a,b;
        while (k1--){
            int x;
            cin>>x;
            a.push_back(x);
        }
        while (k2--){
            int x;
            cin>>x;
            b.push_back(x);
        }
        int ma = *max_element(a.begin(),a.end());
        int mb = *max_element(b.begin(),b.end());
        puts(ma > mb ? "YES":"NO");
    }
    return 0;
}
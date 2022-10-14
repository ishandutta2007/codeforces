#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=1e3+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums={1};
        cin>>arr[1];
        printf("1\n");
        for(int i=2;i<=n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                nums.push_back(1);
            }
            else{
                while(nums.back()!=arr[i]-1)nums.pop_back();
                nums.back()++;
            }
            for(int j=0;j<sz(nums);j++){
                printf("%d%c",nums[j],".\n"[j==sz(nums)-1]);
            }
        }
    }
    return 0;
}
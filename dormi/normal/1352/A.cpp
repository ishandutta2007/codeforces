#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums;
        int mut=1;
        while(n){
            if(n%10){
                nums.push_back(mut*(n%10));
            }
            n/=10;
            mut*=10;
        }
        printf("%d\n",sz(nums));
        for(int x:nums){
            printf("%d ",x);
        }
        printf("\n");
    }
    return 0;
}
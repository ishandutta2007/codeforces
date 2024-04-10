#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
vector<int> a[maxn],b[maxn];
int aa[maxn];
int bb[maxn];
string s;
int main(){
    int n;
    cin>>n;
    int Delta = 0;
    for (int j=0;j<n;j++){
        cin>> s;
        int min_val = 0;
        int pre_sum = 0;
        for (int i=0;i<s.length();i++){
            if (s[i] == '(')pre_sum ++;
            else pre_sum --;
            min_val = min(min_val,pre_sum);
        }
        if (pre_sum == 0 && min_val >= 0){
            Delta ++;
        }else if (pre_sum > 0 && min_val >= 0){
            aa[pre_sum] ++;
        }else if (pre_sum < 0 && min_val >= pre_sum){
            bb[-pre_sum]++;
        }
    }
    int ans = Delta / 2;
    for (int i=1;i<maxn;i++){
        ans += min(aa[i],bb[i]);
    }
    cout<<ans<<endl;
    return 0;
}
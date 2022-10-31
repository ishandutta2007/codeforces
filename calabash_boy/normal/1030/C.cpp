#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
bool check(const vector<int> sum,int n,int sz){
    int Val = sum[sz];
    int pre = sz;
    for (int j=sz;j<=n;j++){
        if (sum[j] == sum[j-1])continue;
        if (sum[j] - sum[pre] == Val){
            pre = j;
        }else if (sum[j] - sum[pre] < Val){
            continue;
        }else{
            return false;
        }
    }
    if (sum[n] == sum[pre])
        return true;
    else
        return false;
}
int main(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n+1);
    a[0] = 0;
    for (int i=0;i<n;i++){
        a[i+1] = s[i] - '0';
        a[i+1] += a[i];
    }
    if (a[n] == 0){
        puts("YES");
        return 0;
    }
    for (int i=1;i<=n-1;i++){
        if (a[i] != a[n] && check(a,n,i)){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
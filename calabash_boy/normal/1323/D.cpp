#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 100;
int n;
int a[maxn];
vector<int> num0,num1;
bool check(int dig){
    num0.clear();
    num1.clear();
    long long cnt = 0;
    int mask = (1 << dig) - 1;
    for (int i=1;i<=n;i++){
        if (a[i] & (1 << dig))num1.push_back(a[i] & mask);
        else num0.push_back(a[i] & mask);
    }
    sort(num0.begin(),num0.end());
    sort(num1.begin(),num1.end());
    long long temp = 0;
    // 0 + 0
    for (int x : num0){
        int limit = (1 << dig) - x;
        int where = lower_bound(num0.begin(),num0.end(),limit) - num0.begin();
        temp += max(0,(int)num0.size() - where);
        if (x + x >= (1 << dig))temp --;
    }
    cnt += temp/2;
    temp = 0;
    // 1 + 1
    for (int x : num1){
        int limit = (1 << dig) - x;
        int where = lower_bound(num1.begin(),num1.end(),limit) - num1.begin();
        temp += max(0,(int)num1.size() - where);
        if (x + x >= (1 << dig))temp --;
    }
    cnt += temp/2;
    temp = 0;
    // 0 + 1
    for (int x : num0){
        int limit = (1 << dig) - x;
        int where = lower_bound(num1.begin(),num1.end(),limit) - num1.begin();
        temp += where;
    }
    cnt += temp;
    return cnt & 1;
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    int ans = 0;
    for (int dig = 0;dig < 28;dig ++){
        if (check(dig)){
            ans += (1 << dig);
        }
    }
    cout<<ans<<endl;
    return 0;
}
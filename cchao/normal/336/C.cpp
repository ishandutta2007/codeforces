#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, arr[100010];
vector<int> ans;
bool solve(int x) {
    if(x==0) {
        printf("%d\n", n);
        for(int i = 0; i < n; ++i) {
            printf("%d ", arr[i]);
        }
        puts("");
        return true;
    }
    ans.clear();
    unsigned int b = 1 << x, t = 0xffffffff;
    for(int i = 0; i < n; ++i) {
        if(arr[i] & b) {t &= arr[i]; ans.push_back(arr[i]);}
    }
    if((b-1) & t) return false;
    cout << ans.size() << endl;

    for(int i = 0; i < ans.size(); ++i) cout << ans[i] << ' ';
    cout << endl;

    return true;
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    for(int i = 31; i >= 0; --i)
        if(solve(i)) break;
    return 0;
}
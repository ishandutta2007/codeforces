#include <iostream>
#include <map>
#include <cstdio>
#include <Vector>

using namespace std;
typedef pair<int, int> pii;

int offset = 0;
int n, arr[100005];
int ans[100005];
vector<int> mn;

int main() {
    // freopen("1.in", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];

        for(int i = n-1; i >=0; --i) {
            if(mn.empty() || arr[i] <= arr[mn[mn.size()-1]]) {
                ans[i] = -1;
                if(mn.empty() || arr[i] != arr[mn[mn.size()-1]])
                    mn.push_back(i);
            } else {
                int lo = 0, hi = mn.size()-1;
                while(lo < hi) {
                    int mid = (lo+hi)/2;
                    if(arr[mn[mid]] >= arr[i]) lo = mid+1;
                    else hi = mid;
                }
                ans[i] = mn[lo]-i-1;
            }
        }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << ((i==n-1)?"\n":" ");
    return 0;
}
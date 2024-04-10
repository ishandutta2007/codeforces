#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n;
    scanf ("%d",&n);
    vector<int> arr,arr2;
    for (int i = 1; i <= n; i+=2) {
        arr.push_back(i);
        arr2.push_back(i+1);
        if (n*2-i+1 != i+1)
        {arr.push_back(n*2-i+1);
        arr2.push_back(n*2-i);
    }
    }
    for (int i : arr2) arr.push_back(i);
    vector<int> psa;
    for (int i : arr) {
        psa.push_back(psa.empty() ? i : psa.back() + i);
    }
    int mx = psa[n-1], mn = mx;
    for (int i = 0; i < n; i++) {
        mx = max(mx,psa[i+n]-psa[i]);
        mn = min(mn,psa[i+n]-psa[i]);
    }
    if (abs(mx-mn) > 1||psa[n*2-1]-psa[n-1] == mn) return !printf ("NO\n");
    printf ("YES\n");
    for (int i : arr) printf ("%d ",i);
    printf ("\n");
    return 0;
}
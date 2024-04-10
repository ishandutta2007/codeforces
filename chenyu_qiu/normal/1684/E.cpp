#include <bits/stdc++.h>
using namespace std;
 
const int N = 100010;
 
int n, k, a[N];
map<int,int> num, dnum;
 
void solve()
{
    num.clear();
    cin >> n >> k;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]), ++ num[a[i]];
    dnum = num;
 
    // mex
    sort(a + 1, a + 1 + n);
    int mex = 0;
    while(num[mex]) ++ mex;
    for(int i = n, j = k; i && j; i--, j--) {
        if(a[i] < mex) break;
        num[mex] = 1, -- num[a[i]];
        while(num[mex]) ++ mex;
    }
 
    // mexdif
    multiset<int> S;
    for(auto i : dnum) {
        if(i.first > mex) S.insert(i.second);
    }
    int dif = mex;
    for(auto i : S) {
        if(k >= i) k -= i;
        else ++ dif;
    }
 
    cout << dif - mex << endl;
}
 
int main()
{
    int test;
    cin >> test;
    while(test--) solve();
 
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

int a[200002], b[200002];
int cnt[200002];
pair<int, int> A[200002];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    if(cnt[x.first] == cnt[y.first]) return x.first < y.first;
    return cnt[x.first] < cnt[y.first];
}

void solve()
{
    int n; cin >> n;
    for(int i=1;i<=n;i++) cnt[i] = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
        A[i] = {a[i], i};
    }
    
    sort(A+1, A+n+1, cmp);
    
    int i = 1;
    while(A[i].first == A[1].first) i++;
    for(;i<=n;)
    {
        int k = i;
        int j = i;
        while(A[j].first == A[i].first)
        {
            if(j <= 2 * k - 2)
            {
                swap(A[j].second, A[2*k-1-j].second);
            }
            j++;
        }
        i = j;
    }
    
    for(int i=1;i<=n;i++) b[A[i].second] = A[i].first;
    for(int i=1;i<=n;i++) cout << b[i] << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}
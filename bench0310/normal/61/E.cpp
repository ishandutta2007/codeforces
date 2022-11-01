#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    ordered_set<int> s;
    vector<long long> l(n);
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
        l[i]=i-s.order_of_key(a[i]);
    }
    s.clear();
    vector<long long> r(n);
    for(int i=n-1;i>=0;i--)
    {
        s.insert(a[i]);
        r[i]=s.order_of_key(a[i]);
    }
    long long res=0;
    for(int i=0;i<n;i++) res+=(l[i]*r[i]);
    printf("%I64d\n",res);
    return 0;
}
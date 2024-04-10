#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, su=0, q=1;
    cin>>n>>k;
    vector <int> sp;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%lld", &x);
        if(x>n-k) su+=x, sp.push_back(a);
    }
    for(int a=0; a+1<sp.size(); a++) q=q*(sp[a+1]-sp[a])%mod;
    cout<<su<<" "<<q;
}
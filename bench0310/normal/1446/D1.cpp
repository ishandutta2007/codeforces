#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> freq(101,0);
    array<int,2> mx={0,0};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        mx=max(mx,{freq[a[i]],a[i]});
    }
    int one=mx[1];
    int res=0;
    for(int two=1;two<=100;two++)
    {
        vector<int> x(2*n+1,-1);
        x[n]=0;
        int s=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==one) s++;
            else if(a[i]==two) s--;
            if(x[s+n]!=-1) res=max(res,i-x[s+n]);
            else x[s+n]=i;
        }
    }
    cout << res << "\n";
    return 0;
}
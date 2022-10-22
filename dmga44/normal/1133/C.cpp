#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

vector<int> v;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cout.tie();

    int n,a,l=0,r=0;
    cin >> n;
    ll sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    while(l<n && r<n)
    {
        while(r<n && v[r]<=v[l]+5)
        {
            sum++;
            r++;
        }
        res=max(res,sum);
        while(r<n && l<n && v[l]<v[r]-5)
        {
            sum--;
            l++;
        }
    }
    db(res)

    return 0;
}
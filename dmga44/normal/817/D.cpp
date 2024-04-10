#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> pii;
typedef pair<ull,pii> pip;
#define MAXN 1000005

ull arr[MAXN];
stack <pip> ma,mi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    ull res=0,sss=0;
    ma.push(pip(arr[0],pii(0,0)));
    mi.push(pip(arr[0],pii(0,0)));
    for(int i=1;i<n;i++)
    {
        ull p1=i,p2=i;
        while(!ma.empty() && ma.top().first<arr[i])
        {
            sss+=(arr[i]-ma.top().first)*(ma.top().second.second-ma.top().second.first+1);
            p1=ma.top().second.first;
            ma.pop();
        }
        ma.push(pip(arr[i],pii(p1,i)));

        while(!mi.empty() && mi.top().first>arr[i])
        {
            sss+=(mi.top().first-arr[i])*(mi.top().second.second-mi.top().second.first+1);
            p2=mi.top().second.first;
            mi.pop();
        }
        mi.push(pip(arr[i],pii(p2,i)));
        res+=sss;
    }

    db(res)

    return 0;
}
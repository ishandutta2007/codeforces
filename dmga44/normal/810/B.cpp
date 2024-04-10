#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef long long ull;
#define MAXN 100005

int arr[MAXN][2];
vector <int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,f;
    ull sum=0;
    cin >> n >> f;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        sum+=min(arr[i][0],arr[i][1]);
        v.push_back(min(2*arr[i][0],arr[i][1])-min(arr[i][0],arr[i][1]));
    }

    sort(v.begin(),v.end());

    for(int i=0;i<f;i++)
        sum+=v[n-i-1];

    db(sum)

    return 0;
}
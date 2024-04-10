#include <bits/stdc++.h>
#define db(x) cout << x << '\n';
using namespace std;
typedef unsigned long long ull;
#define MAXN 100005

int arr[MAXN],n;

ull c(int nn)
{
    ull r=0;
    vector <ull> v;
    for(int i=0;i<n;i++)
        v.push_back(((i+1)*nn)+arr[i]);
    sort(v.begin(),v.end());
    for(int i=0;i<nn;i++)
        r+=v[i];
    return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    ull s,res=0;
    cin >> n >> s;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int ini=0,fin=n;
    while(ini!=fin)
    {
        int m=(ini+fin+1)/2;
        ull x=c(m);
        if(x<=s)
            ini=m,res=x;
        else
            fin=m-1;
    }
    cout << ini << ' ' << res;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int N=300000;
    vector<int> x(N+1,0);
    for(int i=1;i<=N;i++) x[i]=(x[i-1]^i);
    while(t--)
    {
        int a,b;
        cin >> a >> b;
        int res=a;
        if(x[a-1]==b) res+=0;
        else if((x[a-1]^b)!=a) res++;
        else res+=2;
        cout << res << "\n";
    }
    return 0;
}
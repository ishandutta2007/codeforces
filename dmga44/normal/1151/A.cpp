#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string x="ACTG";
    int res=1000;
    for(int i=0;i<=n-4;i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
            sum+=min(abs(s[i+j]-x[j]),abs(abs(s[i+j]-x[j])-26));
        res=min(res,sum);
    }
    db(res)

    return 0;
}
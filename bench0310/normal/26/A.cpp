#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int res=0;
    for(int o=1;o<=n;o++)
    {
        int cnt=0;
        int x=o;
        for(int i=2;i*i<=x;i++)
        {
            if((x%i)==0) cnt++;
            while((x%i)==0) x/=i;
        }
        if(x>1) cnt++;
        res+=(cnt==2);
    }
    cout << res << "\n";
    return 0;
}
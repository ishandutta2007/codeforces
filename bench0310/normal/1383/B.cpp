#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> c(30,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            for(int j=0;j<30;j++) if(a&(1<<j)) c[j]++;
        }
        int res=0; //draw,win,lose
        for(int j=29;j>=0;j--)
        {
            if((c[j]%2)==0) continue;
            int c0=n-c[j];
            int c1=c[j];
            if(c0&1) res=1;
            else res=1+((c1%4)==3);
            break;
        }
        if(res==0) cout << "DRAW\n";
        else if(res==1) cout << "WIN\n";
        else cout << "LOSE\n";
    }
    return 0;
}
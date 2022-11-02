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
        vector<int> p(n);
        for(int i=0;i<n;i++) p[i]=i;
        int s=n;
        int x=n-1;
        while(x>=0)
        {
            while(ll(s)*s>2*x) s--;
            int c=s*s-x;
            reverse(p.begin()+c,p.begin()+x+1);
            x=c-1;
        }
        for(int i=0;i<n;i++) cout << p[i] << " \n"[i==n-1];
    }
    return 0;
}
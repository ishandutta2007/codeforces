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
        string s;
        cin >> n >> s;
        bool a=0,b=0;
        for(char c:s)
        {
            a|=(c=='<');
            b|=(c=='>');
        }
        int res=0;
        for(int i=0;i<n;i++)
        {
            char x=s[i];
            char y=s[(i+1)%n];
            if(x=='-'||y=='-') res++;
            else if((x=='<'&&y=='>')||(x=='>'&&y=='<')) res+=0;
            else res+=(a==0||b==0);
        }
        cout << res << "\n";
    }
    return 0;
}
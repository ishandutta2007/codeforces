#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b,k;
    cin >> a >> b >> k;
    int n=a+b;
    if(a==0||b==1||k==0)
    {
        if(k==0)
        {
            cout << "Yes\n";
            for(int i=0;i<2;i++) cout << string(b,'1')+string(a,'0') << "\n";
        }
        else cout << "No\n";
    }
    else
    {
        if(k<=a+b-2)
        {
            cout << "Yes\n";
            string s(n,'0');
            string t(n,'0');
            s[0]=t[0]='1';
            b--;
            s[n-1]='0';
            t[n-1]='1';
            s[n-1-k]='1';
            t[n-1-k]='0';
            a--;
            b--;
            for(int i=n-2;i>0;i--)
            {
                if(i==n-1-k) continue;
                if(a>0)
                {
                    s[i]=t[i]='0';
                    a--;
                }
                else
                {
                    s[i]=t[i]='1';
                    b--;
                }
            }
            cout << s << "\n";
            cout << t << "\n";
        }
        else cout << "No\n";
    }
    return 0;
}
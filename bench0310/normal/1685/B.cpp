#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        string s;
        cin >> s;
        int ca=0,cb=0;
        for(char x:s)
        {
            ca+=(x=='A');
            cb+=(x=='B');
        }
        bool ok=1;
        ok&=(a+c+d==ca);
        ok&=(b+c+d==cb);
        int both=0;
        int n=s.size();
        int l=0;
        vector<int> one,two;
        int ab=0,ba=0;
        while(l<n)
        {
            int r=l;
            while(r+1<n&&s[r]!=s[r+1]) r++;
            int len=r-l+1;
            if(s[l]==s[r]) both+=(len/2);
            else if(s[l]=='A')
            {
                one.push_back(len/2);
                ab+=(len/2);
            }
            else if(s[l]=='B')
            {
                two.push_back(len/2);
                ba+=(len/2);
            }
            l=r+1;
        }
        if(ab>=c&&ba>=d) c=d=0;
        else if(ab<c&&ba<d)
        {
            c-=ab;
            d-=ba;
        }
        else
        {
            if(ab<c)
            {
                swap(c,d);
                swap(one,two);
                swap(ab,ba);
            }
            //ab>=c && ba<d
            d-=ba;
            ranges::sort(one);
            for(int len:one)
            {
                int t=min(len,c);
                c-=t;
                d-=min(d,max(0,len-t-1));
            }
        }
        ok&=(c+d<=both);
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
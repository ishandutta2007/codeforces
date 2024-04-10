#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        int a,b;
        cin >> a >> b;
        string s=bitset<30>(a).to_string();
        string t=bitset<30>(b).to_string();
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        int x=0,y=0;
        bool ok=(a<=b);
        for(int i=0;i<30;i++)
        {
            x+=(s[i]=='1');
            y+=(t[i]=='1');
            ok&=(x>=y);
        }
        if(ok) cout << "YES\n";
        else cout << "NO\n";
//        bool ok=1;
//        int l=0;
//        while(l<30)
//        {
//            if(s[l]=='0')
//            {
//                if(t[l]=='1')
//                {
//                    ok=0;
//                    break;
//                }
//                l++;
//                continue;
//            }
//            int r=l;
//            while(r+1<30&&s[r+1]=='1') r++;
//            bool all=1;
//            for(int i=l;i<=r;i++) all&=(t[i]=='1');
//            if(all)
//            {
//                l=r+1;
//                continue;
//            }
//            else
//            {
//                for(int i=l;i<=r;i++) s[i]=t[i];
//                if(r+1<30) s[r+1]='1';
//                else ok=0;
//                l=r+1;
//            }
//        }
    }
    return 0;
}
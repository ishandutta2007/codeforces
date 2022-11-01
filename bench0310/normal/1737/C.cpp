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
        auto in=[&](int r,int c)->bool{return (1<=min(r,c)&&max(r,c)<=n);};
        int r=0,c=0;
        int bad=0;
        auto cbad=[&](int a,int b)->int
        {
            int cnt=0;
            for(int x=-1;x<=1;x++) for(int y=-1;y<=1;y++) if(abs(x)+abs(y)==1) cnt+=(!in(a+x,b+y));
            return cnt;
        };
        for(int i=0;i<3;i++)
        {
            int a,b;
            cin >> a >> b;
            bad+=cbad(a,b);
            r^=a;
            c^=b;
        }
        array<int,3> cl={2*n,0,0};
        for(int i:{1,n}) for(int j:{1,n}) cl=min(cl,{abs(r-i)+abs(c-j),i,j});
        int x,y;
        cin >> x >> y;
        auto ok=[&]()->bool
        {
            if(bad<4) return (((x-r)&1)||((y-c)&1));
            else return (x==cl[1]||y==cl[2]);
        }();
        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
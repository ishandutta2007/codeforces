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
        int h,m;
        string s;
        cin >> h >> m >> s;
        int a=stoi(s.substr(0,2));
        int b=stoi(s.substr(3));
        vector<int> rev={0,1,5,-1,-1,2,-1,-1,8,-1};
        auto mv=[&]()
        {
            b=(b+1)%m;
            if(b==0) a=(a+1)%h;
        };
        auto ok=[&]()
        {
            array<int,4> x={b%10,b/10,a%10,a/10};
            bool res=1;
            for(int d:x) res&=(rev[d]!=-1);
            int one=(10*rev[x[0]]+rev[x[1]]);
            int two=(10*rev[x[2]]+rev[x[3]]);
            res&=(0<=one&&one<h&&0<=two&&two<m);
            return res;
        };
        while(!ok()) mv();
        cout << setfill('0') << setw(2) << a << ":" << setw(2) << b << "\n";
    }
    return 0;
}
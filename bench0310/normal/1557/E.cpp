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
        int r=0,c=1;
        auto mv=[&](int nr,int nc)->int //0-bad,1-right,2-win,3-left
        {
            r=nr; c=nc;
            cout << r << " " << c << "\n";
            cout.flush();
            string s;
            cin >> s;
            if(s.size()>=4&&s.substr(s.size()-4,4)=="Left") return 3;
            else if(s=="Done") return 2;
            else if(s.size()>=5&&s.substr(s.size()-5,5)=="Right") return 1;
            else return 0;
        };
        int tmp=mv(8,1);
        if(tmp==2) goto done;
        while(1)
        {
            int x=0;
            if(r!=1)
            {
                x=mv(1,c);
                if(x==2) goto done;
            }
            while(r<8)
            {
                x=mv(r+1,c);
                if(x==2) goto done;
                if(x==1) break;
                if(x==3)
                {
                    x=mv(1,c);
                    if(x==2) goto done;
                    if(x==1) break;
                }
            }
            x=mv(r,c+1);
            if(x==2) goto done;
        }
        done:;
    }
    return 0;
}
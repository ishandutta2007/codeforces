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
        int s,n;
        cin >> s >> n;
        vector<int> res(n+1,0);
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q; //pw,a,i
        auto p=[&](int a,int pw)->int
        {
            string tmp=to_string(a);
            reverse(tmp.begin(),tmp.end());
            if(pw>=(int)tmp.size()) return 0;
            return (tmp[pw]-'0');
        };
        vector<int> ten(10,1);
        for(int i=1;i<=9;i++) ten[i]=(10*ten[i-1]);
        string z=to_string(s);
        reverse(z.begin(),z.end());
        vector<int> opt;
        for(int i=0;i<(int)z.size();i++) for(int j=0;j<(z[i]-'0');j++) opt.push_back(ten[i]);
        while((int)opt.size()>n)
        {
            int x=opt.back();
            opt.pop_back();
            opt.back()+=x;
        }
        vector<int> e;
        for(int i=1;i<=n;i++)
        {
            if(!opt.empty())
            {
                res[i]=opt.back();
                opt.pop_back();
                for(int j=1;j<10;j++) if(p(res[i],j)>=1) q.push({j,-p(res[i],j),i});
            }
            else e.push_back(i);
        }
        while(!e.empty())
        {
            auto [pw,_,i]=q.top();
            q.pop();
            res[i]-=ten[pw];
            if(res[i]==0) e.push_back(i);
            if(p(res[i],pw)>=1) q.push({pw,-p(res[i],pw),i});
            int cnt=10;
            while(cnt>0)
            {
                int x=e.back();
                e.pop_back();
                int c=1;
                if(e.empty()) c=cnt;
                cnt-=c;
                res[x]+=(c*ten[pw-1]);
                if(pw-1>0) q.push({pw-1,-c,x});
            }
        }
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    return 0;
}
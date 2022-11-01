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
        string a,b;
        cin >> a >> b;
        array<int,4> x={0,0,0,0};
        int zero=0,one=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]=='0')
            {
                zero++;
                x[a[i]-'0']++;
            }
            else
            {
                one++;
                x[2+a[i]-'0']++;
            }
        }
        map<array<int,4>,int> d;
        queue<array<int,4>> q;
        auto go=[&](array<int,4> y,int nd)
        {
            if(!d.contains(y))
            {
                d[y]=nd;
                q.push(y);
            }
        };
        go(x,0);
        while(!q.empty())
        {
            array<int,4> tmp=q.front();
            auto [a0,b0,a1,b1]=tmp;
            q.pop();
            if(b0>=1)
            {
                array<int,4> y=tmp;
                y[1]--;
                swap(y[0],y[1]);
                y[1]++;
                swap(y[2],y[3]);
                go(y,d[tmp]+1);
            }
            if(b1>=1)
            {
                array<int,4> y=tmp;
                swap(y[0],y[1]);
                y[3]--;
                swap(y[2],y[3]);
                y[3]++;
                go(y,d[tmp]+1);
            }
        }
        array<int,4> goal={zero,0,0,one};
        if(d.contains(goal)) cout << d[goal] << "\n";
        else cout << "-1\n";
    }
    return 0;
}
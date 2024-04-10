#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;

struct event
{
    bool left;
    bool del;
    int time;
    int base;
    event(bool lf, bool dl, int tm, int bs):
        left(lf),
        del(dl),
        time(tm),
        base(bs)
        {}
};

vector<event> e;
int p;
int time;
int n;

map<int,int> r,l;

bool cmp(const event& e1, const event& e2)
{
    return (e1.time < e2.time);
}

void checkEvent()
{
    while (p<e.size())
    {
        if (time != e[p].time)break;
        if (e[p].left)
        {
            l[e[p].base] += e[p].del?-1:1;
            if (l[e[p].base]==0)l.erase(e[p].base);
        }
        else
        {
            r[e[p].base] += e[p].del?-1:1;
            if (r[e[p].base]==0)r.erase(e[p].base);
        }
        p++;
    }
}

int main()
{
    cin >> n;
    vector<int> pos(n+1);
    for (int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        pos[x]=i;
    }
    for (int i=0; i<n; i++)
    {
        int x,y;
        cin >> x;
        y = pos[x];
        x = i;
        if (x<=y)
        {
            e.push_back(event(true, false, 0, y-x));
            e.push_back(event(true, true, y-x+1, y-x));
            e.push_back(event(false, false, y-x, x-y));
            e.push_back(event(false, true, n-x, x-y));
            e.push_back(event(true, false, n-x, n-x+y));
        }else
        {
            e.push_back(event(false, false, 0, x-y));
            e.push_back(event(false, true, n-x, x-y));
            e.push_back(event(true, false, n-x, y+n-x));
            e.push_back(event(true, true, n-x+y+1, y+n-x));
            e.push_back(event(false, false, n-x+y, -n+x-y));
        }
    }
    sort(e.begin(), e.end(), cmp);
    p = 0;
    vector<int> ans;
    for (time=0; time<n; time++)
    {
        checkEvent();
        int a1 = l.size()?l.begin()->first-time:100000000;
        int a2 = r.size()?r.begin()->first+time:100000000;
        ans.push_back(min(a1,a2));
    }
    cout << ans[0] << endl;
    for (int i=ans.size()-1; i>0; i--)
        cout << ans[i] << endl;
    return 0;
}
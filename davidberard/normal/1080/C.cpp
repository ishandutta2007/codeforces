#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct pt {
    ll x, y;
    pt() {}
    pt(ll a, ll b) : x(a), y(b) {}
};

typedef pair<pt, pt> ppp;

inline ll blackIn(pt bot, pt top)
{
    ll A = abs((top.x-bot.x+1)*(top.y-bot.y+1));
    //cerr << "!! A " << A << endl;
    if(A%2) {
        return A/2 + (bot.x+bot.y)%2;
    }
    return A/2;
}

inline ppp intersection(pt ba, pt ta, pt bb, pt tb)
{
    ppp ans(pt(max(bb.x, ba.x), max(bb.y, ba.y)), pt(min(ta.x, tb.x), min(ta.y, tb.y)));
    //cerr << " a " << ans.first.x << " " << ans.first.y << " " << ans.second.x << " " << ans.second.y << endl;
    if(ans.first.x > ans.second.x || ans.first.y > ans.second.y)
    {
        return ppp(pt(0, 0), pt(-1, -1));
    }
    return ans;
}

inline ll pppArea(ppp x)
{
    return abs((x.second.x-x.first.x+1)*(x.second.y-x.first.y+1));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int TT;
    cin >> TT;
    while(TT--)
    {
        ll N, M;
        cin >> N >> M;
        ll x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        pt p1(x1, y1);
        pt p2(x2, y2);
        pt p3(x3, y3);
        pt p4(x4, y4);
        pt a1(1, 1);
        pt a2(N, M);
        ll A = N*M;
        ll ans = blackIn(a1, a2);
        //cerr << "init black in " << blackIn(a1, a2) << endl;
        ans += pppArea(ppp(p3, p4));
        //cerr << "add black paint " << pppArea(ppp(p3, p4)) << endl;
        ans -= blackIn(p1, p2);
        //cerr << "remove white area " << blackIn(p1, p2) << endl;
        ans -= blackIn(p3, p4);
        //cerr << "remove black area " << blackIn(p3, p4) << endl;
        ppp isec = intersection(p1, p2, p3, p4);
        //cerr << "add isec area " << blackIn(isec.first, isec.second) << " from isec " << isec.first.x << " " << isec.first.y << " " << isec.second.x << " " << isec.second.y << endl;
        ans += blackIn(isec.first, isec.second);
        cout << A-ans << " " << ans << endl;
    }
    return 0;
}
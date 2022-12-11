#include <cstdio>
#include <set>
#include <utility>
static const int MAXN = 200008;
static const int MAXW = 200008;

class side_cutter
{
public:
    side_cutter(int len);
    long long cut(int pos);
protected:
    int _len;
    typedef std::set<std::pair<long long, long long>,
        std::greater<std::pair<long long, long long>>> _segmentlisttype;
    _segmentlisttype _segments;
    typedef std::multiset<long long, std::greater<long long>> _segmentlenlisttype;
    _segmentlenlisttype _seglens;
};

side_cutter::side_cutter(int len) : _len(len) {
    _segments.insert(std::make_pair(0, len));
    _seglens.insert(len);
}

long long side_cutter::cut(int pos)
{
    _segmentlisttype::iterator i = _segments.lower_bound(std::make_pair(pos, 888));
    long long newpos1 = i->first, newlen1 = pos - i->first,
        newpos2 = pos, newlen2 = i->second - newlen1;
    _seglens.erase(_seglens.find(i->second));
    _segments.erase(i);
    _seglens.insert(newlen1);
    _seglens.insert(newlen2);
    _segments.insert(std::make_pair(newpos1, newlen1));
    _segments.insert(std::make_pair(newpos2, newlen2));
    return *_seglens.begin();
}

int main()
{
    long long w, h, n, cutpos; char type;
    scanf("%I64d%I64d%I64d", &w, &h, &n);

    long long lasthor = w, lastvrt = h;
    side_cutter hrzt(w), vrtc(h);
    for (int i = 0; i < n; i++) {
        getchar(); type = getchar();
        scanf("%I64d", &cutpos);
        if (type == 'V') lasthor = hrzt.cut(cutpos);
        else lastvrt = vrtc.cut(cutpos);
        printf("%I64d\n", lasthor * lastvrt);
    }
    return 0;
}
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
vector<int> a, b;
int m;
vector<int> c, d, k;

enum Type
{
    SINGER,
    SONG
};

struct Event
{
    Type type;
    int start;
    int id;

    Event()
    {
    }

    Event(Type type, int start, int id) :
        type(type),
        start(start),
        id(id)
    {
    }
};

bool EventComparator(const Event& lhs, const Event& rhs)
{
    return lhs.start < rhs.start || (lhs.start == rhs.start && lhs.type == SINGER && rhs.type == SONG);
}

vector<Event> e;

set<pair<int, int> > as;

vector<int> ans;

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n;
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    cin >> m;
    c.resize(m);
    d.resize(m);
    k.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i] >> k[i];
    }

    for (int i = 0; i < n; ++i) {
        e.push_back(Event(SONG, a[i], i));
    }

    for (int i = 0; i < m; ++i) {
        e.push_back(Event(SINGER, c[i], i));
    }

    sort(e.begin(), e.end(), EventComparator);

    ans.resize(n);
    for (int i = 0; i < (int) e.size(); ++i) {
        if (e[i].type == SINGER) {
            int id = e[i].id;
            as.insert(make_pair(d[id], id));
        } else {
            int id = e[i].id;
            int finish = b[id];
            int start = a[id];

            pair<int, int> cmp_pair(finish, 0);

            set<pair<int, int> >::iterator itr = as.lower_bound(cmp_pair);

            if (itr == as.end()) {
                cout << "NO" << endl;
                return 0;
            }

            pair<int, int> found_pair = *itr;

            int nid = found_pair.second;

            ans[id] = nid;

            --k[nid];
            if (k[nid] == 0) {
                as.erase(itr);
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
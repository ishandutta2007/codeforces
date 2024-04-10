#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <utility>
#include <iterator>
#include <numeric>
#include <list>
#include <complex>
#include <cstdio>
#include <climits>
#include <iostream>
#include <fstream>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) (x).begin(), (x).end()
#define FE(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define SZ(x) ((int) (x).size())

template<class T>
void splitstr(const string &s, vector<T> &out)
{
    istringstream in(s);
    out.clear();
    copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

static void redirect(int argc, const char **argv)
{
    if (argc > 1)
    {
        static filebuf f;
        f.open(argv[1], ios::in);
        cin.rdbuf(&f);
        if (!cin)
        {
            cerr << "Failed to open '" << argv[1] << "'" << endl;
            exit(1);
        }
    }

    if (argc > 2)
    {
        static filebuf f;
        f.open(argv[2], ios::out | ios::trunc);
        cout.rdbuf(&f);
        if (!cout)
        {
            cerr << "Failed to open '" << argv[2] << "'" << endl;
        }
    }
}

/*** TEMPLATE CODE ENDS HERE */

static const int dr[4] = {-1, 0, 1, 0};
static const int dc[4] = {0, -1, 0, 1};

static void dfs(vector<vector<bool> > &img, int r, int c, vector<pii> &coords)
{
    coords.push_back(pii(r, c));
    img[r][c] = false;
    for (int d = 0; d< 4; d++)
    {
        int r2 = r + dr[d];
        int c2 = c + dc[d];
        if (r2 >= 0 && r2 < SZ(img) && c2 >= 0 && c2 < SZ(img[0]) && img[r2][c2])
            dfs(img, r2, c2, coords);
    }
}

static void dilate(vector<vector<bool> > &img, bool fg)
{
    int R = SZ(img);
    int C = SZ(img[0]);
    vector<vector<bool> > out = img;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (img[i][j] == fg)
                for (int d = 0; d < 4; d++)
                {
                    int r2 = i + dr[d];
                    int c2 = j + dc[d];
                    if (r2 >= 0 && r2 < R && c2 >= 0 && c2 < C)
                        out[r2][c2] = fg;
                }
    img.swap(out);
}

int main(int argc, const char **argv)
{
    redirect(argc, argv);

    int R, C;
    cin >> R >> C;
    vector<vector<bool> > img(R, vector<bool>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            int v;
            cin >> v;
            img[i][j] = v == 1;
        }

    vector<int> rays;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (img[i][j])
            {
                vector<pii> coords;
                dfs(img, i, j, coords);
                int rmin = INT_MAX, rmax = INT_MIN, cmin = INT_MAX, cmax = INT_MIN;
                for (int k = 0; k < SZ(coords); k++)
                {
                    rmin = min(rmin, coords[k].first);
                    rmax = max(rmax, coords[k].first);
                    cmin = min(cmin, coords[k].second);
                    cmax = max(cmax, coords[k].second);
                }
                rmin -= 5;
                rmax += 5;
                cmin -= 5;
                cmax += 5;
                int sR = rmax - rmin + 1;
                int sC = cmax - cmin + 1;
                vector<vector<bool> > sun(sR, vector<bool>(sC));
                for (int k = 0; k < SZ(coords); k++)
                    sun[coords[k].first - rmin][coords[k].second - cmin] = true;

                vector<vector<bool> > middle = sun;
                for (int k = 0; k < 3; k++)
                    dilate(middle, false);
                for (int k = 0; k < 6; k++)
                    dilate(middle, true);

                for (int r = 0; r < sR; r++)
                    for (int c = 0; c < sC; c++)
                        sun[r][c] = sun[r][c] && !middle[r][c];

                dilate(sun, false);
                dilate(sun, true);

#if 0
                ofstream foo("foo.pbm");
                foo << "P2\n" << sC << ' ' << sR << "\n255\n";
                for (int r = 0; r < sR; r++)
                    for (int c = 0; c < sC; c++)
                        foo << (sun[r][c] ? 255 : 0) << ' ';
                foo.close();
#endif

                int nrays = 0;
                for (int r = 0; r < sR; r++)
                    for (int c = 0; c < sC; c++)
                        if (sun[r][c])
                        {
                            vector<pii> dummy;
                            dfs(sun, r, c, dummy);
                            nrays++;
                        }
                rays.push_back(nrays);
            }
        }

    sort(RA(rays));
    cout << rays.size() << '\n';
    for (int i = 0; i < SZ(rays); i++)
    {
        if (i)
            cout << ' ';
        cout << rays[i];
    }
    cout << '\n';

    return 0;
}
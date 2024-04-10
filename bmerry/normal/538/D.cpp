#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
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
    ios::sync_with_stdio(false);
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

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int N;
    cin >> N;
    vs board(N);
    vector<pii> pieces;
    vs out(2 * N - 1, string(2 * N - 1, '.'));
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'o')
                pieces.emplace_back(i, j);
    }
    out[N - 1][N - 1] = 'o';
    for (int dr = -N + 1; dr < N; dr++)
        for (int dc = -N + 1; dc < N; dc++)
        {
            if (dr == 0 && dc == 0)
                continue;
            bool good = true;
            for (const pii &piece : pieces)
            {
                int r = piece.first + dr;
                int c = piece.second +dc;
                if (r >= 0 && r < N && c >= 0 && c < N
                    && board[r][c] == '.')
                {
                    good = false;
                    break;
                }
            }
            if (good)
            {
                out[dr + N - 1][dc + N - 1] = 'x';
                for (const pii &piece : pieces)
                {
                    int r = piece.first + dr;
                    int c = piece.second +dc;
                    if (r >= 0 && r < N && c >= 0 && c < N
                        && board[r][c] == 'x')
                        board[r][c] = 'X';
                }
            }
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 'x')
            {
                cout << "NO\n";
                return 0;
            }

    cout << "YES\n";
    for (const string &row : out)
        cout << row << '\n';

    return 0;
}
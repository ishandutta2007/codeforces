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
    string s;
    cin >> s;
    int freq[26] = {};
    for (char c : s)
        freq[c - 'a']++;
    deque<int> odd;
    for (int i = 0; i < 26; i++)
        if (freq[i] & 1)
            odd.push_back(i);
    while (odd.size() > 1)
    {
        freq[odd[0]]++;
        freq[odd.back()]--;
        odd.pop_front();
        odd.pop_back();
    }

    string h;
    for (int i = 0; i < 26; i++)
    {
        char c = i + 'a';
        int F = freq[i] / 2;
        for (int j = 0; j < F; j++)
            h += c;
    }
    string p = h;
    reverse(RA(h));
    if (!odd.empty())
        p += 'a' + odd[0];
    p += h;
    cout << p << '\n';

    return 0;
}
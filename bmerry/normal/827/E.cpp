// WRONG ANSWER

#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
# include <sys/time.h>
# include <sys/resource.h>
#endif

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795028841971693993751
#endif

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;

typedef vector<string> vs;
typedef long long ll;
typedef complex<double> pnt;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll) (x).size())

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
#ifndef ONLINE_JUDGE
    struct rlimit rlim;
    getrlimit(RLIMIT_STACK, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_STACK, &rlim);
    getrlimit(RLIMIT_DATA, &rlim);
    rlim.rlim_cur = 256 * 1024 * 1024;
    setrlimit(RLIMIT_DATA, &rlim);
#endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
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

template<typename Traits>
class FFT
{
public:
    typedef typename Traits::type type;

private:
    template<typename It>
    static It fft_r(It first, It last, It tmp_first, It tmp_last, type g)
    {
        std::size_t S = last - first;
        if (S == 1)
            return first;
        else if (S == 2)
        {
            type a = *first;
            type b = *(first + 1);
            *first = a + b;
            *(first + 1) = a - b;
            return first;
        }
        std::size_t H = S / 2;
        It even = tmp_first;
        It odd = tmp_first + H;
        for (std::size_t i = 0; i < H; i++)
        {
            *(even + i) = *(first + 2 * i);
            *(odd + i) = *(first + 2 * i + 1);
        }
        type g2 = g * g;
        even = fft_r(even, odd, first, first + H, g2);
        odd = fft_r(odd, tmp_last, first, first + H, g2);
        if (&*even == &*first)
        {
            swap(first, tmp_first);
            swap(last, tmp_last);
        }
        type p = 1;
        for (std::size_t i = 0; i < H; i++)
        {
            type q = even[i];
            type r = p * odd[i];
            *(first + i) = q + r;
            *(first + i + H) = q - r;
            p *= g;
        }
        return first;
    }

public:
    static std::vector<type> fft(std::vector<type> a)
    {
        std::size_t S = a.size();
        assert(S > 0 && (S & (S - 1)) == 0); // power of 2
        std::vector<type> tmp(S);
        auto pos = fft_r(a.begin(), a.end(), tmp.begin(), tmp.end(), Traits::generator(S, true));
        if (&*pos == &*tmp.begin())
            a.swap(tmp);
        return a;
    }

    static std::vector<type> rfft(std::vector<type> a)
    {
        std::size_t S = a.size();
        assert(S > 0 && (S & (S - 1)) == 0); // power of 2
        std::vector<type> tmp(S);
        auto pos = fft_r(a.begin(), a.end(), tmp.begin(), tmp.end(), Traits::generator(S, false));
        if (&*pos == &*tmp.begin())
            a.swap(tmp);
        type iS = Traits::inverse(S);
        for (std::size_t i = 0; i < S; i++)
            a[i] *= iS;
        return a;
    }

    static std::vector<type> convolve(const std::vector<type> &a, const std::vector<type> &b)
    {
        assert(!a.empty());
        assert(!b.empty());
        std::size_t S = 1;
        while (S < a.size() + b.size() - 1)
            S *= 2;

        std::vector<type> pa(S), pb(S);
        std::copy(a.begin(), a.end(), pa.begin());
        std::copy(b.begin(), b.end(), pb.begin());
        std::vector<type> A = fft(pa);
        std::vector<type> B = fft(pb);
        for (std::size_t i = 0; i < S; i++)
            A[i] *= B[i];
        pa = rfft(A);
        pa.resize(a.size() + b.size() - 1);
        return pa;
    }
};

template<typename T>
class fft_traits_complex
{
public:
    typedef std::complex<T> type;

    static type inverse(type value)
    {
        return 1.0 / value;
    }

    static type generator(std::size_t S, bool invert)
    {
        type g = std::polar(1.0, 2 * M_PI / S);
        if (invert)
            g = conj(g);
        return g;
    }
};

typedef FFT<fft_traits_complex<double>> CFFT;

/*** TEMPLATE CODE ENDS HERE */

int main(int argc, const char **argv)
{
    redirect(argc, argv);
    int T;
    cin >> T;
    for (int cas = 0; cas < T; cas++)
    {
        int N;
        string s;
        cin >> N >> s;
        vector<complex<double>> seq(N);
        for (int i = 0; i < N; i++)
        {
            if (s[i] == 'V')
                seq[i] = 1.0;
            else if (s[i] == 'K')
                seq[i] = complex<double>(0.0, 1.0);
        }
        vector<complex<double>> rseq = seq;
        reverse(RA(rseq));
        auto conv = CFFT::convolve(seq, rseq);
        vector<bool> period(N + 1, true);
        for (int i = 0; i < N - 1; i++)
            if (fabs(conv[i].imag() > 0.5))
                period[N - 1 - i] = false;

        int P = 1;
        for (int i = 1; i < N; i++)
        {
            for (int j = 2 * i; j < N; j += i)
                if (!period[j])
                {
                    period[i] = false;
                    break;
                }
            P += period[i];
        }
        cout << P << '\n';
        for (int i = 1; i < N; i++)
            if (period[i])
                cout << i << ' ';
        cout << N << '\n';
    }

    return 0;
}
#include <stdio.h>
#include <algorithm>
#include <cmath>
class FastIO
{
  public:
    FastIO()
    {
        size_ = 1 << 13;
        rpos_ = wpos_ = 0;
        next_ = 0;
    }
    int readInt()
    {
        skip();
        bool sign = true;
        unsigned int r = 0;
        if (next_ == '-' || next_ == '+')
        {
            sign = next_ == '+';
            next_ = next();
        }
        while (next_ >= '0' && next_ <= '9')
        {
            r = (r << 3) + (r << 1) + next_ - '0';
            next_ = next();
        }
        return sign ? r : -r;
    }
    long long readLong()
    {
        skip();
        bool sign = true;
        unsigned long long r = 0;
        if (next_ == '-' || next_ == '+')
        {
            sign = next_ == '+';
            next_ = next();
        }
        while (next_ >= '0' && next_ <= '9')
        {
            r = (r << 3) + (r << 1) + next_ - '0';
            next_ = next();
        }
        return sign ? r : -r;
    }
    double readDouble()
    {
        skip();
        bool sign = true;
        unsigned long long r = 0;
        if (next_ == '-' || next_ == '+')
        {
            sign = next_ == '+';
            next_ = next();
        }
        while (next_ >= '0' && next_ <= '9')
        {
            r = (r << 3) + (r << 1) + next_ - '0';
            next_ = next();
        }
        if (next_ != '.')
        {
            return r;
        }
        next_ = next();
        unsigned long long s = 0;
        unsigned long long divisor = 1;
        while (next_ >= '0' && next_ <= '9')
        {
            s = (s << 3) + (s << 1) + next_ - '0';
            divisor = (divisor << 3) + (divisor << 1);
            next_ = next();
        }
        double combine = r + (double)s / divisor;
        return sign ? combine : -combine;
    }
    int readString(char *data)
    {
        char *ptr = data;
        skip();
        while (next_ > 32)
        {
            (*ptr++) = next_;
            next_ = next();
        }
        return ptr - data;
    }
    char readChar()
    {
        skip();
        char c = next_;
        next_ = next();
        return c;
    }
  private:
    void skip()
    {
        while (next_ >= 0 && next_ <= 32)
        {
            next_ = next();
        }
    }
    int next()
    {
        while (rpos_ == wpos_)
        {
            rpos_ = 0;
            wpos_ = fread(read_, 1, size_, stdin);
            if (wpos_ == 0 && feof(stdin))
            {
                return -1;
            }
        }
        return read_[rpos_++];
    }
    int size_;
    char read_[1 << 13];
    int rpos_;
    int wpos_;
    int next_;
} io;

#define SWAP(a, b, type) \
    {                    \
        type tmp = a;    \
        a = b;           \
        b = tmp;         \
    }
#define MOD(a, n) ((a) % (n) + (n)) % (n)
#define ABS(x) (x) < 0 ? -(x) : (x)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#ifdef ONLINE_JUDGE
int debug = 0;
#else
int debug = 1;
#endif
#define ASSERT(x)                                       \
    if (debug)                                          \
        if (!(x))                                       \
        {                                               \
            printf("Assert fail on %d line", __LINE__); \
            exit(1);                                    \
        }
typedef long long ll;
typedef char boolean;
//typedef __uint128_t ui128;

int g_points[100000][2];
int g_n;

double Power2(double v)
{
    return v * v;
}

double MinimunRadius(double x)
{
    double r = 0;
    for(int i = 0; i < g_n; i++)
    {
        r = std::max(r, (Power2(x - g_points[i][0]) / g_points[i][1] + g_points[i][1]) / 2);
    }
    return r;
}

double Solve(){
    double l = -1e7;
    double r = 1e7;
    while(r - l > 1e-6)
    {
        double p1 = l + (r - l) / 3;
        double p2 = l + (r - l) * 2 / 3;
        if(MinimunRadius(p1) >= MinimunRadius(p2))
        {
            l = p1;
        }
        else
        {
            r = p2;
        }
    }
    return MinimunRadius(l);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/database/testcase/code.in", "r", stdin);
    freopen("D:/database/testcase/code.out", "w", stdout);
#endif

    //g_n = io.readInt();
    scanf("%d", &g_n);
    bool yLessThan0 = false;
    bool yGreaterThan0 = false;
    for (int i = 0; i < g_n; i++)
    {
        //g_points[i][0] = io.readInt();
        //g_points[i][1] = io.readInt();
        scanf("%d %d", &g_points[i][0], &g_points[i][1]);
        yLessThan0 = yLessThan0 || g_points[i][1] < 0;
        yGreaterThan0 = yGreaterThan0 || g_points[i][1] > 0;
        g_points[i][1] = std::abs(g_points[i][1]);
    }
    if(yLessThan0 && yGreaterThan0)
    {
        printf("%d", -1);
        return 0;
    }
    printf("%.8lf", Solve());
    return 0;
}
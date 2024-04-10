#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")


/**
 * -------------------------------------------------------
 * Template begin
 * -------------------------------------------------------
 */
#include <bits/stdc++.h>
using std::deque;
using std::pair;
using std::vector;

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
#define BIT_AT(n, i) (((n) >> i) & 1)
#ifdef ONLINE_JUDGE
#define ASSERT(x) ;
#else
#define ASSERT(x)                                   \
    if (!(x))                                       \
    {                                               \
        printf("Assert fail on %d line", __LINE__); \
        exit(1);                                    \
    }
#endif
typedef unsigned int uint;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

template <class T>
T Read()
{
    T n = 0;
    char c = getchar();
    bool sign = true;
    while (c < '0' || c > '9')
    {
        if (c == '-')
        {
            sign = !sign;
        }
        c = getchar();
    }
    while (c <= '9' && c >= '0')
    {
        n = n * 10 + c - '0';
        c = getchar();
    }
    return sign ? n : -n;
}

#define ReadI Read<int>
#define ReadLL Read<ll>

/**
 * -------------------------------------------------------
 * Template end 
 * -------------------------------------------------------
 */

int M = 1e9 + 7;

class Matrix
{
  public:
    Matrix(int r, int c)
    {
        r_ = r;
        c_ = c;
        mat_ = new int *[r];
        for (int i = 0; i < r; i++)
        {
            mat_[i] = new int[c];
        }
    }
    int *operator[](int i)
    {
        return mat_[i];
    }
    void asZero()
    {
        for (int i = 0; i < r_; i++)
        {
            for (int j = 0; j < c_; j++)
            {
                mat_[i][j] = 0;
            }
        }
    }

    void asStandard()
    {
        asZero();
        for (int i = 0; i < r_; i++)
        {
            mat_[i][i] = 1;
        }
    }

    static Matrix *plus(Matrix *a, Matrix *b)
    {
        int r = a->r_;
        int c = a->c_;
        Matrix *mat = new Matrix(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
            {
                mat->mat_[i][j] = (a->mat_[i][j] + b->mat_[i][j]) % M;
            }
        }
        return mat;
    }

    static Matrix *mul(Matrix *a, Matrix *b)
    {
        int r = a->r_;
        int c = b->c_;
        int m = a->c_;
        Matrix *mat = new Matrix(r, c);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                mat->mat_[i][j] = 0;
                for (int k = 0; k < m; k++)
                {
                    mat->mat_[i][j] = (mat->mat_[i][j] + (ll)a->mat_[i][k] * b->mat_[k][j]) % M;
                }
            }
        }
        return mat;
    }

    static bool equal(Matrix *a, Matrix *b)
    {
        if (a->r_ != b->r_ || a->c_ != b->c_)
        {
            return false;
        }
        int r = a->r_;
        int c = a->c_;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (a->mat_[i][j] != b->mat_[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    static Matrix *pow(Matrix *x, int n)
    {
        if (n == 0)
        {
            Matrix *one = new Matrix(x->r_, x->c_);
            one->asStandard();
            return one;
        }
        Matrix *p = pow(x, n >> 1);
        p = mul(p, p);
        if (n & 1)
        {
            p = mul(p, x);
        }
        return p;
    }

    void debug(){
        printf("\n");
        for(int i = 0; i < r_; i++)
        {
            for(int j = 0; j < c_; j++)
            {
                printf("%d ", mat_[i][j]);
            }
            printf("\n");
        }
    }
  private:
    int **mat_;
    int r_;
    int c_;
};

int BIT_COUNT[1 << 5];

bool test()
{
    Matrix a(2, 2);
    Matrix b(2, 2);
    a.asStandard();
    b.asZero();
    b[0][0] = 1;
    b[0][1] = 987213;
    b[1][1] = 3;
    b[1][0] = 9417131;

    ASSERT(Matrix::equal(Matrix::mul(&a, &b), &b));
    return true;
}

bool test3()
{
    Matrix b(2, 2);
    b.asZero();
    b[0][0] = 1;
    b[0][1] = 987213;
    b[1][1] = 3;
    b[1][0] = 9417131;

    Matrix *c = &b;



    ASSERT(Matrix::equal(c, Matrix::pow(&b, 1)));
    return true;
}



bool test2()
{
    Matrix b(2, 2);
    b.asZero();
    b[0][0] = 1;
    b[0][1] = 987213;
    b[1][1] = 3;
    b[1][0] = 9417131;

    Matrix *c = new Matrix(2, 2);
    c->asStandard();
    for (int i = 0; i < 10; i++)
    {
        c = Matrix::mul(c, &b);
    }

    ASSERT(Matrix::equal(c, Matrix::pow(&b, 10)));
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D:/database/testcase/code.in", "r", stdin);
    freopen("D:/database/testcase/code.out", "w", stdout);
#endif

    //ASSERT(test());
    //ASSERT(test3());
    //ASSERT(test2());

    int n = ReadI();
    int k = ReadI();
    int m = ReadI();

    int mask = 1 << m;
    int highest_bit = mask >> 1;
    BIT_COUNT[0] = 0;
    for (int i = 1; i < mask; i++)
    {
        BIT_COUNT[i] = BIT_COUNT[i & (i - 1)] + 1;
    }

    int mat_size = (k + 1) * mask;
    Matrix *transition = new Matrix(mat_size, mat_size);
    transition->asZero();

#define GET_I(n) (n / mask)
#define GET_J(n) (n % mask)
#define INDEX_OF(i, j) ((i)*mask + (j))

    for (int i = 0; i < mat_size; i++)
    {
        int step = GET_I(i);
        int bit = GET_J(i);
        if (BIT_COUNT[bit] > step)
        {
            continue;
        }
        if (bit & 1)
        {
            (*transition)[i][INDEX_OF(step - 1, bit >> 1)] = BIT_COUNT[bit >> 1] + 1;
            (*transition)[i][INDEX_OF(step - 1, (bit >> 1) | highest_bit)] = BIT_COUNT[(bit >> 1) | highest_bit] + 1;
        }
        else
        {
            (*transition)[i][INDEX_OF(step, bit >> 1)] = 1;
            (*transition)[i][INDEX_OF(step, (bit >> 1) | highest_bit)] = 1;
        }
    }
    
    Matrix *transition_n_times = Matrix::pow(transition, n);

    Matrix *init = new Matrix(mat_size, 1);
    init->asZero();
    (*init)[INDEX_OF(0, 0)][0] = 1;

    init = Matrix::mul(transition_n_times, init);
    //init->debug();

    int sum = 0;
    for (int i = 0; i < mask; i++)
    {
        sum = (sum + (*init)[INDEX_OF(k, i)][0]) % M;
    }

    printf("%d", sum);

    return 0;
}
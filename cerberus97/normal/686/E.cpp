#include <iostream>
#include <iomanip>
#include <cmath>

#define setMax(a, b) (a<b)?(a=b):0
#define setMin(a, b) (a>b)?(a=b):0

using namespace std;

const int N = (int)1e5;
const long long LL_UP = (long long)9e18;

struct point
{
    long long x, y, z;

}s[N];

bool doesAnswerExist(long long c, int n, point &ans)
{
    long long A, B, C, D, E, F, G, H;
    A = C = E = G = -LL_UP;
    B = D = F = H = LL_UP;

    for (int i = 0; i < n; ++i)
    {
        setMax(A, s[i].x + s[i].y + s[i].z - c);
        setMin(B, s[i].x + s[i].y + s[i].z + c);
        setMax(C, -s[i].x + s[i].y + s[i].z - c);
        setMin(D, -s[i].x + s[i].y + s[i].z + c);
        setMax(E, s[i].x - s[i].y + s[i].z - c);
        setMin(F, s[i].x - s[i].y + s[i].z + c);
        setMax(G, s[i].x + s[i].y - s[i].z - c);
        setMin(H, s[i].x + s[i].y - s[i].z + c);
    }

    if (A > B or C > D or E > F or G > H)
        return false;

    long long xMin = max((G+E), (A-D)), xMax = min((B-C), (H+F));

    if (xMin % 2)
        ++xMin;

    xMin /= 2;
    xMax /= 2;

    if (xMin > xMax)
        return false;

    for (ans.x = xMin; ans.x <= xMax; ++ans.x)
    {
        long long ypz = max(A-ans.x, C+ans.x), ymz = max(ans.x-F, G-ans.x);

        if ((long long)fabs(ymz + ypz) % 2 == 1)
        {
            if (ypz < min(B-ans.x, D+ans.x))
                ++ypz;

            else if (ymz < min(ans.x-E, H-ans.x))
                ++ymz;

            else
                continue;
        }

        ans.y = (ypz+ymz)/2;
        ans.z = (ypz-ymz)/2;
        return true;
    }

    return false;
}

void binSearch(long long l, long long r, int n, point &ans)
{
    if (l == r)
    {
        doesAnswerExist(l, n, ans);
        return;
    }

    long long mid = (l+r)/2;

    if (doesAnswerExist(mid, n, ans))
        binSearch(l, mid, n, ans);

    else
        binSearch(mid+1, r, n, ans);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int t, n;

    cin >> t;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> s[i].x >> s[i].y >> s[i].z;

        point ans;
        binSearch(0, (long long)3e18, n, ans);

        cout << ans.x << ' ' << ans.y << ' ' << ans.z << '\n';
    }

    return 0;
}
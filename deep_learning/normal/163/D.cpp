#include <bits/stdc++.h>
#define S(a, b, c) ((a) * (b) + (a + b) * (c))
using namespace std;
typedef unsigned long long ull;
struct PrimeFactor
{
    ull v, c, u;
    PrimeFactor()
    {
        u = 0;
    }
};
PrimeFactor arr[1000];
ull V;
ull alimit, blimit;
ull a = 1, b = 1, c;
ull mins = 0, ma, mb, mc;
ull Vres;
int k = 0;
void dfsB(int ni)
{
#ifdef DEBUG
    cout << a << ", " << b << endl;
#endif // DEBUG
    if (ni < 0)
    {
        if (a > b)
        {
            return;
        }
        ull c2 = c / b;
        ull res = S(a, b, c2);
        if (res < mins)
        {
            mins = res;
            ma = a;
            mb = b;
            mc = c2;
        }
        return;
    }
//  if (arr[ni].u < arr[ni].c)
//  {
//      arr[ni].u++;
//      b *= arr[ni].v;
//      if (b <= blimit)
//      {
//          dfsB(ni);
//      }
//      b /= arr[ni].v;
//      arr[ni].u--;
//  }
    ull ob = b, ou = arr[ni].u;
    for (ull i = arr[ni].u; i < arr[ni].c; i++)
    {
        arr[ni].u++;
        b *= arr[ni].v;
#ifdef DEBUG
        cout << b << endl;
#endif // DEBUG
        if (b <= blimit)
        {
            dfsB(ni - 1);
        }
//      else
//      {
//          cout << "b: kill " << b << endl;
//      }
//      a /= arr[ni].v;
//      arr[ni].u--;
    }
    b = ob;
    arr[ni].u = ou;
    dfsB(ni - 1);
}
void dfsA(int ni)
{
    if (ni < 0)
    {
        c = V / a;
        if (2 * a * sqrt(c) + c >= mins)
        {
            return;
        }
        blimit = (ull)(sqrt(c) + 0.5);
        dfsB(k - 1);
        return;
    }
    ull oa = a, ou = arr[ni].u;
    for (ull i = arr[ni].u; i < arr[ni].c; i++)
    {
        arr[ni].u++;
        a *= arr[ni].v;
#ifdef DEBUG
        cout << a << endl;
#endif // DEBUG
        if (a <= alimit)
        {
            dfsA(ni - 1);
        }
//      else
//      {
//          cout << "a: kill " << a << endl;
//      }
//      a /= arr[ni].v;
//      arr[ni].u--;
    }
    a = oa;
    arr[ni].u = ou;
    dfsA(ni - 1);
}
bool comp(const PrimeFactor &a, const PrimeFactor &b)
{
    return a.v < b.v;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("163d.in", "r", stdin);
#endif // ONLINE_JUDGE
    int d = 0;
    ios::sync_with_stdio(false);
    cin >> d;
    while (d--)
    {
        cin >> k;
        a = 1;
        b = 1;
        V = 1;
        mins = (ull)(-1);
        for (int i = 0; i < k; i++)
        {
            cin >> arr[i].v >> arr[i].c;
            for (int j = 0; j < arr[i].c; j++)
            {
//              if (!j)
//              {
//                  arr[i].p.push_back(1);
//              }
//              else
//              {
//                  arr[i].p.push_back
//                  (arr[i].p[j - 1] * arr[i].v);
//              }
                V *= arr[i].v;
            }
//          V *= arr[i].p[arr[i].c];
        }
        sort(arr, arr + k, comp);
#ifdef DEBUG
        cout << arr[k - 1].v << endl;
#endif // DEBUG
        alimit = (ull)(pow(V, 1.0 / 3) + 0.5);
        dfsA(k - 1);
        cout << (mins << 1)
             << " " << ma
             << " " << mb
             << " " << mc
             << endl;
    }
    return 0;
}
#include <iostream>
using namespace std;

const int module = 1e9 + 9;

int a[1001][31][31][31][2];
int n,h;

void upd(int num, int i1, int i2, int i3, int f, int x)
{
    if (i2<i1)swap(i1,i2);
    if (i3<i1)swap(i1,i3);
    if (i3<i2)swap(i2,i3);
    int& da = a[num][i1][i2][i3][f];
    da = (da+x)%module;
}

int main()
{
    cin >> n >> h;
    a[1][0][0][0][1]=4;
    for (int i=2; i<=n; i++)
        for (int i1=0; i1<=h; i1++)
            for (int i2=i1; i2<=h; i2++)
                for (int i3=i2; i3<=h; i3++)
                    for (int f=0; f<2; f++)
                    {
                        int x = a[i-1][i1][i2][i3][f];
                        int ni1 = (i1+1<=h && i1!=0)?i1+1:0;
                        int ni2 = (i2+1<=h && i2!=0)?i2+1:0;
                        int ni3 = (i3+1<=h && i3!=0)?i3+1:0;
                        upd(i,ni1,ni2,ni3,f||i<=h,x);
                        upd(i,f||i<=h,ni2,ni3,i<=h||i1!=0&&i1<h,x);
                        upd(i,ni1,f||i<=h,ni3,i<=h||i2!=0&&i2<h,x);
                        upd(i,ni1,ni2,f||i<=h,i<=h||i3!=0&&i3<h,x);
                    }
    int ans = 0;
    for (int i1=0; i1<=h; i1++)
        for (int i2=i1; i2<=h; i2++)
            for (int i3=i2; i3<=h; i3++)
                for (int f=0; f<2; f++)
                    if (f!=0 || i1!=0 && i1!=h ||
                                i2!=0 && i2!=h ||
                                i3!=0 && i3!=h)
                        ans = (ans + a[n][i1][i2][i3][f])%module;
    cout << ans << endl;
    return 0;
}
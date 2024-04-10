#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define E (1e-6)
using namespace std;
int main()
{
    int nx;
    cin >> nx;
    double x[nx], r = 0;
    for(int k = 0; k < nx; k ++)
    {
        cin >> x[k];
        if(x[k] > r) r = x[k];
    }

    int ny;
    cin >> ny;
    double y[ny];
    for(int k =0 ; k < ny; k++)
        cin >> y[k];

    int nz;
    cin >> nz;
    double z[nz];
    for(int k = 0; k < nz;k++)
        cin >> z[k];

    double a, b, st;
    cin >> a >> b;
    st = b / a;
    double best = 0,tmp;
    for(int j = 0; j < ny; j++)
        for(int k = 0; k < nz; k++)
        {
            tmp = b*y[j] / (a*z[k] + b*y[j]);
            if(tmp > best) best = tmp;
        }
    printf("%.12f", r * sqrt(best));

    return 0;
}
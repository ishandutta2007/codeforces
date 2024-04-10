#include <iostream>

using namespace std;
int a, b, k, n, h, fa, ta, tb, fb, c, d, e, f1a, f1b, g;

int main()
{
    cin >> n >> h >> a >> b >> k;
    for(int i=0;i<k;i++)
    {
        cin >> fa >> ta >> fb >> tb;
        if(ta<a)
        {
            c=a-ta;
            f1a=a;
        }
        if(ta>b)
        {
            c=ta-b;
            f1a=b;
        }
        if(ta>=a && ta<=b)
        {
            c=0;
            f1a=ta;
        }
        if(tb<a)
            {
            d=a-tb;
            f1b=a;
            }
        if(tb>b)
            {
            d=tb-b;
            f1b=b;
            }
        if(tb>=a && tb<=b)
        {
            d=0;
            f1b=tb;
        }
        if(fa>fb)
            e=fa-fb;
        else e=fb-fa;
        if(f1b>f1a)
            g=f1b-f1a;
        else g=f1a-f1b;
        if(fa==fb)
        {
            if(ta>tb)
                cout << ta-tb << endl;
            else cout << tb-ta << endl;
        }
        else
        cout << c+d+e+g << endl;
    }
    return 0;
}
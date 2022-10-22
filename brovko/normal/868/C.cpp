#include <bits/stdc++.h>

using namespace std;
int n, k, x[4];
map < pair <pair <int, int>, pair <int, int> > , bool> m;
bool f(int y)
{
    int a1=y%2;
    int a2=y/2%2;
    int a3=y/4%2;
    int a4=y/8%2;
    return m[{{a1, a2}, {a3, a4}}];
}

int main()
{
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(j<k)
                cin >> x[j];
            else x[j]=0;
        }
        m[{{x[0], x[1]}, {x[2], x[3]}}]=true;
    }
    for(int i=0;i<16;i++)
        for(int j=0;j<16;j++)
        for(int i1=0;i1<16;i1++)
        for(int i2=0;i2<16;i2++)
            if(f(i)&&f(j)&&f(i1)&&f(i2))
        {
            if((i%2+j%2+i1%2+i2%2<=2)&&(i/2%2+j/2%2+i1/2%2+i2/2%2<=2)&&(i/4%2+j/4%2+i1/4%2+i2/4%2<=2)&&(i/8%2+j/8%2+i1/8%2+i2/8%2<=2))
            {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
    return 0;
}
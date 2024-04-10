#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int m[228];
int n;

bool check(int k)
{
    if (k==0)
    return 0;
    int val[228];
    for (int i=0;i<228;i++)
        val[i]=228;
    ;
    for (int i=0;i<n;i++)
    {
        int mind = 0;
        for (int j=1;j<k;j++)
        {
            if (val[mind] < val[j])
                mind = j;
        }
        if (val[mind]>m[i])
        {
            val[mind] = m[i];
        }
        else
        if (val[mind] == 0)
        {
            return 0;
        }
        else
        {
            val[mind]--;
        }
    }
return 1;
}

bool cmp(int hh,int hhh)
{
    return hh>hhh;
}

int main()
{

    cin >> n;
    for (int i=0;i<n;i++)
        cin>>m[i];
    sort(m,m+n,cmp);
    int a=0;
    int b=102;
    int maxok=-1;
    check(1);
    while (a<=b)
    {
        if (check((a+b)/2))
        {
                maxok=(a+b)/2;
                b = maxok-1;
        }
        else
        {
            a = (a+b)/2+1;
        }
    }
    cout << maxok;
    return 0;
}
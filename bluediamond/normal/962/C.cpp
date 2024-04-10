#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int cif[15],l;
int best=-1;

int st[15];

void bkt(int strat,int nr,int cate)
{
    if(strat==l)
    {
        int rad=(int)sqrt(double(nr));
        if(rad*rad==nr && cate>0)
            best=max(best,cate);
        return;
    }
    bkt(strat+1,nr,cate);
    if(cate==0 && cif[strat+1]==0)
        return;
    bkt(strat+1,10*nr+cif[strat+1],cate+1);
}
int main()
{
    cin>>n;
    while(n>0)
    {
        cif[++l]=n%10;
        n/=10;
    }
    reverse(cif+1,cif+l+1);
    bkt(0,0,0);
    if(best==-1)
        cout<<-1;
    else
        cout<<l-best;
    return 0;
}
/**
9 2 4
*...*...*

**/
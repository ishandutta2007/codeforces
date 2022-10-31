#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

struct bign
{
    int bit[100];
    bign()
    {
        memset(bit,0,sizeof(bit));
    }
    bign(string s)
    {
        memset(bit,0,sizeof(bit));
        int i = 0;
        for(int k = s.length()-1;k >=0 ;k--)
        {
            bit[i++] =  s[k] - '0';
        }
    }
    int msb()
    {
        for(int k = 99; k >= 0 ;k--)
        {
            if(bit[k] !=0 ) return k;
        }
        return 0;
    }
    bool operator<=(bign b)
    {
        int ma = msb(), mb = b.msb();
        if(ma != mb) return ma < mb;
        else
        {
            while(ma >= 0)
            {
                if(bit[ma] != b.bit[mb]) return bit[ma] < b.bit[mb];
                ma--;
                mb--;
            }
        }
        return true;
    }
    void show()
    {
        for(int k = msb();k >= 0;k--)
            printf("%d",bit[k]);
        putchar('\n');
    }
    bign operator-(bign b)
    {
        bign res = *this;
        for(int k = 0; k < 99; k++)
        {
            res.bit[k] -= b.bit[k];
            while(res.bit[k] < 0)
            {
                res.bit[k] += 10;
                res.bit[k+1] -= 1;
            }
        }
        return res;
    }
};

int main()
{
    string sa,sb;
    cin >> sa >> sb;
    bign a(sa), b , tmp(sb),prev;
    b = a-tmp;
//    a.show();
//    b.show();
    //cout << (b <= a) << endl;
    prev = tmp = a;
    //cout << tmp.msb() << endl;
    for(int k = 0; k <= tmp.msb(); k++)
    {
        tmp.bit[k] = 9;
        for(int j = k+1; j <= tmp.msb() && tmp.bit[j] > 0 && !(tmp <= a && b <= tmp); j++)
        {
            //tmp.show();
            tmp.bit[j]--;
        }
        if(tmp <= a && b <= tmp) prev = tmp;
    }
    prev.show();

    return 0;
}
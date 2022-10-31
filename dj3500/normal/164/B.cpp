#ifdef VX_PRECOMPILED
#include "precomp.h"
#else
#include<string>
#include<iostream>
#include<sstream>
#include<assert.h>
#include<cstdio>
#include<map>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<queue>
#include<functional>
#include<set>
#include<sys/stat.h>
#include<numeric>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#endif
typedef long long int64;
#define long int64
#define var(q,s) typeof(s) q = s
#define for_each(q,s) for(var(q,(s).begin()); q!=(s).end(); q++)
using namespace std;

//=========================================================
// program:
//
int la, lb;
int a[2000000];
int b[2000000];
int bpos[1000001];

void deb(int* x, int xlow, int xhigh)
{
    cout<<"[";
    for (int i=xlow; i<xhigh; i++) {
        cout << " " << x[i];
    }
    cout<<" ]";
}
int seen[1000001];

int solve()
{
    fill(bpos, bpos+1000001, -1);
    for (int i=0; i<lb; i++) {
        bpos[ b[i] ] = i;
    }
    int res = 0;
    
    for (int i=la; i<la*2; i++) {
        a[i] = a[i - la];
    }
    int alow = -1;
    int ahigh = alow + la;
    int blow = -1;
    int last = -1;
    int len = 0;
    
    // now we rotate a...
    fill(seen, seen + 1000001, 0);
    int steps = 0;
    for (int i=0; i<la; i++) {
        alow++;
        ahigh++;
        len = max(len - 1, 0);
        if (len == 0) {
            if (bpos[a[alow]] != -1) {
                blow = bpos[a[alow]];
            } else {
                blow += lb - 1;
                if (blow >= lb) {
                    blow -= lb;
                }
            }
            last = -1;
        } else {
            blow = bpos[a[alow]];
        }
        while (len < la) {
            int y = bpos[a[alow + len]];
            bool good = false;
            if ( (y != -1) && (last!=-1) ) {
                if ( y < blow ) {
                    if (last < blow) {
                        good = (y > last);
                    } else {
                        good = (y > last - lb);
                    }
                } else {
                    if (last >= blow) {
                        good = (y > last);
                    } else {
                        good = (y - lb > last );
                    }
                }
            } else if (y != -1) {
                good = true;
            }
            //cout << "  attempt with "<<a[alow + len]<<" : "<<(y-blow)<<endl;
            if (good) {
                seen[a[alow + len] ]++;
                assert( seen[a[alow + len]]  <= 2);

                last = y;
                steps ++;
                assert (steps < 4000000);
                len++;
            } else {
                break;
            }
        }
        res = std::max(res, len);
        //deb(a, alow, ahigh);
        //cout <<" .. ";
        //deb(b, blow, bhigh);
        //cout <<" .. "<<len<<endl;
    }
    
    
    
    
    return res;
}

inline void init(){}
//=========================================================
// I/O:
//
int main()
{
    init();
    ios_base::sync_with_stdio(0);
    bool prev = false;
    while( cin >> la >> lb) {
        if (prev) {
            cout << endl;
        }
        prev = true;
        for (int i=0; i<la; i++) {
            cin >> a[i];
        }
        for (int i=0; i<lb; i++) {
            cin >> b[i];
        }
        cout << solve() << endl;


    }
    return 0;
}
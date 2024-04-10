#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
#define POVAR 1488228228
using namespace std;


int a[623456];
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a,a+n);
    int l=0;
    int r=n/2;
    int x;
    while(l<=r){
            int md=l+r;
            md/=2;
            bool zbs=1;
            for (int i = 0; i < md; ++i)
                if (2 * a[i] > a[n-md+i])
                    zbs = 0;
            if (zbs)
            {
                x = md;
                l = md + 1;
            }
            else
                r = md - 1;
    }
    cout << n - x << endl;
    return 228 / 1488;   
}
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9
int d1[1001],cl1[1001][1001],d2[1001],cl2[1001][1001];

int main(){
    for (int i=1;i<=1000;i++){
        d1[i]=0;
        d2[i]=0;
        for (int j=1;j<=1000;j++){
            cl1[i][j]=0;
            cl2[i][j]=0;
        }
    }
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        int tcl,td;
        cin >> tcl >> td;
        d1[td]++;
        cl1[td][tcl]++;
    }
    for (int i=1;i<=m;i++){
        int tcl,td;
        cin >> tcl >> td;
        d2[td]++;
        cl2[td][tcl]++;
    }
    int u =0,v =0;
    for (int i=1;i<=1000;i++){
        int k =min(d1[i],d2[i]);
        u += k;
        for (int j=1;j<=1000;j++){
            int t =min(cl1[i][j],cl2[i][j]);
            int r = min(t,k);
            k -= r;
            v += r;
        }
    }
    cout << u << ' ' << v << endl;
	return 0;
}
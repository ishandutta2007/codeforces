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
struct cube{
    int color, size, id;
};

cube a[111111];
__int64 ta = 0;
vector<__int64> g[111111];
int color[111111];
int fc,sc;

bool cmp1(cube t1, cube t2){
    return (t1.color<t2.color || (t1.color==t2.color && t1.size>t2.size));
}

int main(){
    int n;
    cin >> n;
    a[0].color = -1;
    for (int i=1;i<=n;i++){
        cin >> a[i].color >> a[i].size;
        a[i].id = i;
    }
    sort(a, a+n+1, cmp1);

    int cnt = 0;
    for (int i=1;i<=n;i++){
        if (i==1 || a[i].color!=a[i-1].color){
            cnt++;
            color[cnt]=a[i].color;
        }
        __int64 t = a[i].size;
        if (g[cnt].size()!=0)
            t = t + g[cnt][g[cnt].size()-1];
        g[cnt].push_back(t);
    }

    int max_size = 0;
    for (int i=1;i<=cnt;i++)
        if (g[i].size()>max_size)
            max_size = g[i].size();
    for (int i=0;i<max_size;i++){

        int fmax =-1;
        for (int j=1;j<=cnt;j++)
            if (g[j].size()>i && (fmax==-1 || g[j][i]>g[fmax][i]))
                fmax = j;
        if (fmax ==-1)continue;
        int smax = -1;
        for (int j=1;j<=cnt;j++)
            if (j!=fmax && g[j].size()>i && (smax==-1 || g[j][i]>g[smax][i]))
                smax = j;
        if (smax!=-1 && g[fmax][i]+g[smax][i]>ta){
            ta = g[fmax][i]+g[smax][i];
            fc = fmax;
            sc = smax;
        }
        if (i+1<max_size){
        smax = -1;
        for (int j=1;j<=cnt;j++)
            if (j!=fmax && g[j].size()>i+1 && (smax==-1 || g[j][i+1]>g[smax][i+1]))
                smax = j;
        if (smax!=-1 && g[fmax][i]+g[smax][i+1]>ta){
            ta = g[fmax][i]+g[smax][i+1];
            fc = fmax;
            sc = smax;
        }
        }
        if (i<1)continue;
        smax = -1;
        for (int j=1;j<=cnt;j++)
            if (j!=fmax && g[j].size()>i-1 && (smax==-1 || g[j][i-1]>g[smax][i-1]))
                smax = j;
        if (smax!=-1 && g[fmax][i]+g[smax][i-1]>ta){
            ta = g[fmax][i]+g[smax][i-1];
            fc = smax;
            sc = fmax;
        }
    }
    cout << ta << endl;
    int i1, i2, c1=color[fc], c2=color[sc];
    for (int i=1;i<=n;i++)
        if (a[i].color ==c1){
            i1 = i;
            break;
        }
    for (int i=1;i<=n;i++)
        if (a[i].color ==c2){
            i2 = i;
            break;
        }
    if (g[sc].size()>g[fc].size()){
        cout << g[fc].size()*2 +1 << endl;
        cout << a[i2++].id << ' ';
    }else
        cout << g[fc].size()*2 << endl;
    while (i1<=n && a[i1].color==c1)
        cout << a[i1++].id << ' ' << a[i2++].id << ' ';
    cout << endl;
	return 0;
}
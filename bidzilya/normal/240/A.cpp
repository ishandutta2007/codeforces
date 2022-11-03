#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n,m,k,nk;
int mn[100],mx[100];
bool lv[100];
string name[100];

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n >> k;
    nk = n - k;
    for (int i=0;i<n;i++)
        lv[i] = false;
    for (int i=0;i<k;i++){
        int x;
        cin >> x;
        x--;
        lv[x] = true;
    }
    cin >> m;
    for (int i=0;i<m;i++){
        int cnt,fr,cur,tnk;
        cin >> name[i];
        cin >> cnt;
        fr = cur = 0;
        tnk = nk;
        for (int j=0;j<cnt;j++){
            int x;
            cin >> x;
            x--;
            if (x==-1)
                fr++;
            else
            if (lv[x])
                cur++;
            else
                tnk--;
        }
        mn[i] = cur + max(0,fr-tnk);
        mx[i] = min(k, cur+fr);
    }

    for (int i=0;i<m;i++){
        int t = -1, d = -1;
        for (int j=0;j<m;j++)
            if (j!=i){
                if (t==-1 || mx[j]>t)
                    t = mx[j];
                if (d==-1 || mn[j]>d)
                    d = mn[j];
            }
        if (mn[i]>=t)
            cout << 0;
        else
        if (mx[i]<d)
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }

    return 0;
}
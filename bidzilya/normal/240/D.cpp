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

int n,m;
int a[200000],b[200000];
int q[2][200000],c[2][200000];
int cnt[2];
vector<int> ans[4];

void build(int v,int st){
    cnt[v] = 0;
    int i1=0,i2=0;
    while (i1<n || i2<m){
        if (cnt[v]==0){
            if (a[i1]==st){
                q[v][cnt[v]]=st;
                c[v][cnt[v]]=1;
                cnt[v]++;
                ans[v].push_back(i1+1);
                i1++;
                continue;
            }
            if (b[i2]==st){
                q[v][cnt[v]]=st;
                c[v][cnt[v]]=1;
                cnt[v]++;
                ans[v].push_back(i2+n+1);
                i2++;
                continue;
            }
            q[v][cnt[v]]=(st+1)%2;
            c[v][cnt[v]]=1;
            cnt[v]++;
            ans[v].push_back(i1+1);
            i1++;
            continue;
        }
        if (i1<n && a[i1]==q[v][cnt[v]-1]){
            c[v][cnt[v]-1]++;
            ans[v].push_back(i1+1);
            i1++;
            continue;
        }
        if (i2<m && b[i2]==q[v][cnt[v]-1]){
            c[v][cnt[v]-1]++;
            ans[v].push_back(i2+n+1);
            i2++;
            continue;
        }
        if (i1<n){
            q[v][cnt[v]]=a[i1];
            c[v][cnt[v]]=1;
            cnt[v]++;
            ans[v].push_back(i1+1);
            i1++;
            continue;
        }
        q[v][cnt[v]]=b[i2];
        c[v][cnt[v]]=1;
        ans[v].push_back(i2+1+n);
        i2++;
        cnt[v]++;
    }
}

void find(int v1, int v2){
    int y = 0;
    while (1){
        if (q[v1][y]==0){
            if (y+1==cnt[v1])break;
            ans[v2].push_back(c[v1][y]);
            c[v1][y+1] += c[v1][y];
            y++;
            continue;
        }
        ans[v2].push_back(c[v1][y]);
        c[v1][y+1] += c[v1][y];
        y++;
        if (y==cnt[v1])
            cnt[v1]++;
    }
}

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    cin >> n;
    for (int i=0;i<n;i++)
        cin >> a[i];
    cin >> m;
    for (int i=0;i<m;i++)
        cin >> b[i];
    build(0,0);
    build(1,1);
    find(0,2);
    find(1,3);
    if (ans[2].size()<=ans[3].size()){
        for (int i=0;i<ans[0].size();i++)
            cout << ans[0][i] << " ";
        cout << endl;
        cout << ans[2].size() << endl;
        for (int i=0;i<ans[2].size();i++)
            cout << ans[2][i] << " ";
        cout << endl;
    }else {
        for (int i=0;i<ans[1].size();i++)
            cout << ans[1][i] << " ";
        cout << endl;
        cout << ans[3].size() << endl;
        for (int i=0;i<ans[3].size();i++)
            cout << ans[3][i] << " ";
        cout << endl;
    }
    return 0;
}
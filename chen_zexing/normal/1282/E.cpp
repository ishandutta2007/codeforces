#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
unordered_map <long long,int> mp,mp2;
long long hash(int x,int y){
    return 1LL*1000000000*x+y;
}
struct edge{
    int x,y;
}a[300005];
struct triangle{
    int x,y,z;
}b[100005];
vector <int> v[100005];
int f[100005];
queue <int> q;
vector <int> v2[300005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, x = 0;
        mp.clear();
        mp2.clear();
        while (!q.empty()) q.pop();
        scanf("%d", &n);
        for (int i = 1; i <= 3 * n; i++) v2[i].clear();
        for (int i = 1; i <= n - 2; i++) {
            scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
            if (b[i].x > b[i].y) swap(b[i].x, b[i].y);
            if (b[i].y > b[i].z) swap(b[i].y, b[i].z);
            if (b[i].x > b[i].z) swap(b[i].x, b[i].z);
            if (b[i].x > b[i].y) swap(b[i].x, b[i].y);
            if (b[i].y > b[i].z) swap(b[i].y, b[i].z);
            if (b[i].x > b[i].z) swap(b[i].x, b[i].z);
            //cout<<b[i].x<<" "<<b[i].y<<" "<<b[i].z<<endl;
            if (mp[hash(b[i].x, b[i].y)] == 0) {
                a[++x] = edge{b[i].x, b[i].y};
                v2[x].push_back(i);
                mp[hash(b[i].x, b[i].y)] = 1;
                mp2[hash(b[i].x, b[i].y)] = x;
            }
            else {
                int t = mp2[hash(b[i].x, b[i].y)];
                v2[t].push_back(i);
                mp[hash(b[i].x, b[i].y)]++;
            }
            if (mp[hash(b[i].y, b[i].z)] == 0) {
                a[++x] = edge{b[i].y, b[i].z};
                v2[x].push_back(i);
                mp[hash(b[i].y, b[i].z)] = 1;
                mp2[hash(b[i].y, b[i].z)] = x;
            }
            else {
                int t = mp2[hash(b[i].y, b[i].z)];
                v2[t].push_back(i);
                mp[hash(b[i].y, b[i].z)]++;
            }
            if (mp[hash(b[i].x, b[i].z)] == 0) {
                a[++x] = edge{b[i].x, b[i].z};
                v2[x].push_back(i);
                mp[hash(b[i].x, b[i].z)] = 1;
                mp2[hash(b[i].x, b[i].z)] = x;
            }
            else {
                int t = mp2[hash(b[i].x, b[i].z)];
                v2[t].push_back(i);
                mp[hash(b[i].x, b[i].z)]++;
            }
        }
        for (int i = 1; i <= n; i++) v[i].clear(), f[i] = 0;
        for (int i = 1; i <= x; i++) {
            if (mp[hash(a[i].x, a[i].y)] == 1) {
                v[a[i].x].push_back(a[i].y), v[a[i].y].push_back(a[i].x);
            }
        }
        int cnt = 1, now = 1;
        f[1] = 1;
        printf("1 ");
        while (cnt < n) {
            for (int i = 0; i < v[now].size(); i++)
                if (f[v[now][i]] == 0) {
                    printf("%d ", v[now][i]);
                    f[v[now][i]] = 1;
                    now = v[now][i];
                    cnt++;
                    break;
                }
        }
        printf("\n");
        if(n==3){
            printf("1\n");
            continue;
        }
        cnt = 0;
        for (int i = 1; i <= n - 2; i++) {
            if (mp[hash(b[i].x, b[i].y)] + mp[hash(b[i].x, b[i].z)] + mp[hash(b[i].y, b[i].z)] == 4) {
                q.push(i);
            }
        }
        while (cnt < n - 2) {
            int t = q.front();
            printf("%d ", t);
            q.pop();
            mp[hash(b[t].x, b[t].y)]--;
            mp[hash(b[t].x, b[t].z)]--;
            mp[hash(b[t].y, b[t].z)]--;
            int e1 = mp2[hash(b[t].x, b[t].y)], e2 = mp2[hash(b[t].y, b[t].z)], e3 = mp2[hash(b[t].x, b[t].z)];
            for (int i = 0; i < v2[e1].size(); i++) {
                if (mp[hash(b[v2[e1][i]].x, b[v2[e1][i]].y)] + mp[hash(b[v2[e1][i]].x, b[v2[e1][i]].z)] +
                    mp[hash(b[v2[e1][i]].y, b[v2[e1][i]].z)] == 4) {
                    //cnt++;
                    q.push(v2[e1][i]);
                }
            }
            for (int i = 0; i < v2[e2].size(); i++) {
                if (mp[hash(b[v2[e2][i]].x, b[v2[e2][i]].y)] + mp[hash(b[v2[e2][i]].x, b[v2[e2][i]].z)] +
                    mp[hash(b[v2[e2][i]].y, b[v2[e2][i]].z)] == 4) {
                    //cnt++;
                    q.push(v2[e2][i]);
                }
            }
            for (int i = 0; i < v2[e3].size(); i++) {
                if (mp[hash(b[v2[e3][i]].x, b[v2[e3][i]].y)] + mp[hash(b[v2[e3][i]].x, b[v2[e3][i]].z)] +
                    mp[hash(b[v2[e3][i]].y, b[v2[e3][i]].z)] == 4) {
                    //cnt++;
                    q.push(v2[e3][i]);
                }
            }
            cnt++;
        }
        printf("\n");
    }
    return 0;
}
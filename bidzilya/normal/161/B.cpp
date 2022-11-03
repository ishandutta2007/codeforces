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
struct block{
    int id,cost;
};
int cnt_tab=0, cnt_car=0;
block tab[1001],car[1001];
int n,k;
vector<block> g[1001];
int a[1001],b[1001];

bool cmp(block t1, block t2){
    return (t1.cost < t2.cost);
}

int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
        if (b[i]==1){
            tab[++cnt_tab].id = i;
            tab[cnt_tab].cost = a[i];
        }else{
            car[++cnt_car].id = i;
            car[cnt_car].cost = a[i];
        }
    }
    sort(tab, tab+cnt_tab+1, cmp);
    sort(car, car+cnt_car+1, cmp);
    int por = min(cnt_tab,k);
    for (int i=1;i<=por;i++){
        block temp = tab[cnt_tab];
        cnt_tab--;
        g[i].push_back(temp);
    }
    while (cnt_tab>0){
        block temp = tab[cnt_tab];
        cnt_tab--;
        g[por].push_back(temp);
    }
    if (por==k){
        while (cnt_car>0){
            block temp = car[cnt_car];
            cnt_car--;
            g[por].push_back(temp);
        }
    }else{
        for (int i=por+1;i<=k;i++){
            block temp = car[cnt_car];
            cnt_car--;
            g[i].push_back(temp);
        }
        while (cnt_car>0){
            block temp = car[cnt_car];
            cnt_car--;
            g[k].push_back(temp);
        }
    }
    double ans = 0.0;
    for (int i=1;i<=k;i++){
        bool is_tab = 0;
        for (int j=0;j<g[i].size();j++)
            if (b[g[i][j].id]==1){
                is_tab = 1;
                break;
            }
        int ind =0;
        for (int j=1;j<g[i].size();j++)
            if (g[i][j].cost<g[i][ind].cost)
                ind = j;
        for (int j=0;j<g[i].size();j++)
            if (j!=ind)
                ans = ans + g[i][j].cost;
        if (is_tab)
            ans = ans + 0.5*g[i][ind].cost;
        else
            ans = ans + g[i][ind].cost;
    }
    printf("%.1lf\n", ans);
    for (int i=1;i<=k;i++){
        printf("%d ", g[i].size());
        for (int j=0;j<g[i].size();j++)
            printf("%d ",g[i][j].id);
        printf("\n");
    }

	return 0;
}
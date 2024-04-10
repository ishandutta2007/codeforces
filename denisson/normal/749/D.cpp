#include <bits/stdc++.h>

using namespace std;

int n, q;
pair<int, int> a[200007];
bool was[200007];
int color[200007];
vector<int> uk[200007];
vector<int> d;

int main(){
    for (int i = 0; i < 200007; i++)
        color[i] = -1;
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    for (int i = n - 1; i >= 0; i--){
        if (!was[a[i].first])
            d.push_back(a[i].first), was[a[i].first] = 1;
    }
    for (int i = 0; i < n; i++){
        uk[a[i].first].push_back(a[i].second);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++){
        int sz;
        scanf("%d", &sz);
        for (int j = 0; j < sz; j++){
            int num;
            scanf("%d", &num);
            color[num] = i;
        }
        int win = -1, win2 = -1;
        for (int j = 0; j < d.size(); j++){
            if (color[d[j]] != i){
                if (win == -1)
                    win = d[j];
                else {
                    if (win2 == -1)
                        win2 = d[j];
                    else
                        break;
                }
            }
        }
        //cout << win << ' ' << win2 << endl;
        if (win == win2 && win == -1){
            printf("0 0\n");
            continue;
        }
        if (win2 == -1){
            printf("%d %d\n", win, uk[win][0]);
            continue;
        }
        int last = uk[win2].back();
        int take = *upper_bound(uk[win].begin(), uk[win].end(), last);
        printf("%d %d\n", win, take);
    }
}
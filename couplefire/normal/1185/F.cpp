#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int pow2[9];
    pow2[0] = 1;
    for(int i = 1; i<9; i++) pow2[i] = pow2[i-1]*2;
    int num[512] = {0};
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        int huh = 0;
        for(int j = 0; j<a; j++){
            int b; cin >> b;
            huh += pow2[b-1];
        }
        num[huh]++;
    }
    vector<pair<int, int>> pizza[512];
    for(int i = 0; i<m; i++){
        int c; cin >> c;
        int a; cin >> a;
        int huh = 0;
        for(int j = 0; j<a; j++){
            int b; cin >> b;
            huh += pow2[b-1];
        }
        pizza[huh].push_back({c, i});
    }
    for(int i = 0; i<512; i++){
        sort(pizza[i].begin(), pizza[i].end());
    }
    int ben[512] = {0};
    for(int i = 0; i<512; i++){
        for(int j = 0; j<512; j++){
            if((i & j) != j) continue;
            ben[i]+=num[j];
        }
    }
    int best = 0;
    int cost = 2000000010;
    int ind1, ind2;
    for(int i = 0; i<512; i++){
        for(int j = 0; j<512; j++){
            int temp = (i|j);
            if(i == j){
                if(pizza[i].size() < 2) continue;
                if(ben[temp] > best){
                    best = ben[temp];
                    cost = pizza[i][0].first+pizza[i][1].first;
                    ind1 = pizza[i][0].second;
                    ind2 = pizza[i][1].second;
                }
                else if(ben[temp] == best && pizza[i][0].first+pizza[i][1].first < cost){
                    cost = pizza[i][0].first+pizza[i][1].first;
                    ind1 = pizza[i][0].second;
                    ind2 = pizza[i][1].second;
                }
            }
            else{
                if(pizza[i].size() == 0 || pizza[j].size() == 0) continue;
                if(ben[temp] > best){
                    best = ben[temp];
                    cost = pizza[i][0].first+pizza[j][0].first;
                    ind1 = pizza[i][0].second;
                    ind2 = pizza[j][0].second;
                }
                else if(ben[temp] == best && pizza[i][0].first+pizza[j][0].first < cost){
                    cost = pizza[i][0].first+pizza[j][0].first;
                    ind1 = pizza[i][0].second;
                    ind2 = pizza[j][0].second;
                }
            }
        }
    }
    cout << ind1 +1 << " " << ind2+1 << endl;
}
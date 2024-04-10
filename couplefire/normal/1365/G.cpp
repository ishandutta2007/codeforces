#include<bits/stdc++.h>

using namespace std;

vector<vector<int> > lists, query(13);
long long val[13], res;
int n;

int main(){
    cin >> n;
    for(int i = 0; i < (1 << 13); i++){
        if(__builtin_popcount(i) == 6){
            lists.push_back(vector<int>());
            for(int j = 0; j < 13; j++){
                if(i & (1 << j)){
                    lists[lists.size() - 1].push_back(j);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int x : lists[i]){
            query[x].push_back(i + 1);
        }
    }
    for(int i = 0; i < 13; i++){
        if(query[i].size()){
            cout << "? " << query[i].size() << " ";
            for(int x : query[i]){
                cout << x << " ";
            }
            cout << endl;
            cin >> val[i];
        }
    }
    cout << "! ";
    for(int i = 0; i < n; i++){
        res = 0;
        for(int j = 0; j < 13; j++){
            if(find(lists[i].begin(), lists[i].end(), j) == lists[i].end())
                res |= val[j];
        }
        cout << res << " ";
    }
    cout << endl;
    return 0;
}
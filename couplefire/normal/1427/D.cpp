#include <bits/stdc++.h>
using namespace std;

bool sorted(vector<int> &arr){
    for(int i = 1; i<(int)arr.size(); i++) if(arr[i] < arr[i-1]) return false;
    return 1;
}

void apply(vector<int>& arr, vector<int>&res){
    vector<vector<int>> lol;
    int index = 0;
    for(auto i : res){
        lol.push_back(vector<int>());
        while(i--){
            lol.back().push_back(arr[index++]);
        }
    }
    reverse(lol.begin(), lol.end());
    arr.clear();
    for(auto i : lol){
        for(auto j : i) arr.push_back(j);
    }
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin >> arr[i];
    vector<vector<int>> res;
    int curmin = 1, curmax = n;
    while(!sorted(arr)){
        res.push_back(vector<int>());
        int posmin, posmax;
        for(int i = 0; i<n; i++){
            if(arr[i] == curmin) posmin = i;
            if(arr[i] == curmax) posmax = i;
        }
        if(posmin < posmax){
            if(curmin != 1) res.back().push_back(curmin-1);
            res.back().push_back(posmin-curmin+2);
            if(posmax-posmin != 1) res.back().push_back(posmax-posmin-1);
            res.back().push_back(n-posmax-curmin+1);
            if(curmin != 1) res.back().push_back(curmin-1);
            apply(arr, res.back());
            res.push_back(vector<int>());
            if(curmin != 1) res.back().push_back(curmin-1);
            res.back().push_back(1);
            if(n != curmin*2) res.back().push_back(n-curmin-curmin);
            res.back().push_back(1);
            if(curmin != 1) res.back().push_back(curmin-1);
            apply(arr, res.back());
        }
        else{
            if(curmin != 1){
                res.back().push_back(curmin-1);
                if(n != curmin*2-2) res.back().push_back(n-curmin*2+2);
                res.back().push_back(curmin-1);
                apply(arr, res.back());
                res.push_back(vector<int>());
            }
            swap(posmin, posmax);
            if(curmin != 1) res.back().push_back(curmin-1);
            res.back().push_back(posmin-curmin+2);
            if(posmax-posmin != 1) res.back().push_back(posmax-posmin-1);
            res.back().push_back(n-posmax-curmin+1);
            if(curmin != 1) res.back().push_back(curmin-1);
            apply(arr, res.back());
        }
        curmin++;
        curmax--;
    }
    cout << res.size() << endl;
    for(auto i : res){
        cout << i.size() << " ";
        for(auto j : i) cout << j << " ";
        cout << endl;
    }
}
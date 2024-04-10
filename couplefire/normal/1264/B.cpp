#include <bits/stdc++.h>
using namespace std;
vector<int> re;

int main(){
    //freopen("a.in", "r", stdin);
    vector<int> arr(4);
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    int sum = arr[0]+arr[1]+arr[2]+arr[3];
    re.resize(sum);
    bool work = true;
    vector<int> arr2 = arr;
    vector<int> arr3 = arr;
    vector<int> arr4 = arr;
    int cur = 0;
    for(int i = 0; i<sum; i++){
        if(cur -1 >= 0 && arr[cur-1] > 0){
            re[i] = --cur;
            --arr[cur];
        }
        else if(cur + 1 <= 3 && arr[cur+1] > 0){
            re[i] = ++cur;
            --arr[cur];
        }
        else work = false;
    }
    if(work){
        cout << "YES" << endl;
        for(auto i : re) cout << i << " ";
        cout << endl;
        return 0;
    }
    cur = 1;
    work = true;
    re.clear();
    re.resize(sum);
    for(int i = 0; i<sum; i++){
        if(cur -1 >= 0 && arr2[cur-1] > 0){
            re[i] = --cur;
            --arr2[cur];
        }
        else if(cur + 1 <= 3 && arr2[cur+1] > 0){
            re[i] = ++cur;
            --arr2[cur];
        }
        else work = false;
    }
    if(work){
        cout << "YES" << endl;
        for(auto i : re) cout << i << " ";
        cout << endl;
        return 0;
    }
    cur = 2;
    work = true;
    re.clear();
    re.resize(sum);
    for(int i = 0; i<sum; i++){
        if(cur -1 >= 0 && arr3[cur-1] > 0){
            re[i] = --cur;
            --arr3[cur];
        }
        else if(cur + 1 <= 3 && arr3[cur+1] > 0){
            re[i] = ++cur;
            --arr3[cur];
        }
        else work = false;
    }
    if(work){
        cout << "YES" << endl;
        for(auto i : re) cout << i << " ";
        cout << endl;
        return 0;
    }
    cur = 3;
    work = true;
    re.clear();
    re.resize(sum);
    for(int i = 0; i<sum; i++){
        if(cur -1 >= 0 && arr4[cur-1] > 0){
            re[i] = --cur;
            --arr4[cur];
        }
        else if(cur + 1 <= 3 && arr4[cur+1] > 0){
            re[i] = ++cur;
            --arr4[cur];
        }
        else work = false;
    }
    if(work){
        cout << "YES" << endl;
        for(auto i : re) cout << i << " ";
        cout << endl;
        return 0;
    }
    cout << "NO" << endl;
}
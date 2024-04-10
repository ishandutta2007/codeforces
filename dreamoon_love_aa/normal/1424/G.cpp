#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
int main() {
    int n,x,y;
    vector <pair <int,int> > v;
    cin >> n;
    while(n--){
        cin >> x >> y;
        v.push_back({x,1});
        v.push_back({y,-1});
    }
    sort(v.begin(),v.end());
    int maxp = 0,minx = 0,cnt = 0;
    for(auto a:v){
        if(a.second == 1){
            cnt++;
            if(maxp < cnt){
                maxp = cnt;
                minx = a.first;
            }
        }else if(a.second == -1){
            cnt--;
        }
    }
    cout << minx << " " << maxp << endl;
    return 0;
}
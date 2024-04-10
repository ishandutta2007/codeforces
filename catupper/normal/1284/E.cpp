#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n, x[2750], y[2750];
Int ans;

bool cw(Int a, Int b, Int c){
    Int x1 = x[b] - x[a];
    Int y1 = y[b] - y[a];
    Int x2 = x[c] - x[a];
    Int y2 = y[c] - y[a];
    return x1 * y2 - x2 * y1 < 0;
}

void calc(vector<Int> poInts, Int x){
    Int n = poInts.size();
//    cout << x << endl;
    for(Int l = 0, r = 0;l < n;l++){
        //      cout << ::x[poInts[l]] << ". " << y[poInts[l]]<< endl;
        while(cw(poInts[l], x, poInts[(r+1)%n])){
            (r+=1) %= n;
        }
//        cout << l << " " << r << endl;
        Int cnt = (r + n - l) % n;
        ans -= cnt * (cnt - 1) / 2 * (cnt - 2) / 3;
    }
}

int main(){
    cin >> n;
    for(Int i = 0;i < n;i++){
        cin >> x[i] >> y[i];
    }
    ans = n * (n-1) * (n-2)/2 * (n-3) /3 * (n-4) / 4;
    for(Int i = 0;i < n;i++){
        vector<Int> poInts;
        for(Int j = 0;j < n;j++){
            if(j == i)continue;
            poInts.push_back(j);
        }
        auto comp = [i](int a, int b){
                        Int x1 = x[a] - x[i];
                        Int y1 = y[a] - y[i];
                        Int x2 = x[b] - x[i];
                        Int y2 = y[b] - y[i];
                        int pos1 = y1 > 0 || (y1 == 0 && x1 > 0);                  int pos2 = y2 > 0 || (y2 == 0 && x2 > 0);
                        if(pos1 != pos2)return pos1 > pos2;
                        return x1 * y2 - y1 * x2 > 0;
                    };

        sort(poInts.begin(), poInts.end(), comp);
        calc(poInts, i);
    }
    cout << ans << endl;
    return 0;
}
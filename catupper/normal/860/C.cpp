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
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;



int to_number(string x){
    int res = 0;
    int l = x.size();
    if(x[0] == '0')return 0;
    for(auto c: x){
        if(c < '0' || '9' < c)return 0;
        res *= 10;
        res += c - '0';
    }
    return res;
}

string f[110000];
int t[110000];
int pos[110000];


int files[110000];
vector<int> go_to[2];
vector<int> frees[2];
vector<string> commands;
void move(int ind, int t){
    commands.push_back("move " + f[ind] + " " + to_string(t));
}

int e = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> f[i] >> t[i];
        e += t[i];
    }
    bool done = true;
    for(int i = 1;i <= n;i++){
        int num = to_number(f[i]);
        if(num > n)num = 0;
        if(num > 0)files[num] = i;
        if(t[i] == 1 && 0 < num && num <= e)continue;
        if(t[i] == 0 && e < num)continue;
        pos[i] = num;
        done = false;
        if(num > 0)frees[t[i]].push_back(i);
        else go_to[t[i]].push_back(i);
    }
    for(auto x:frees[0])go_to[0].push_back(x);
    for(auto x:frees[1])go_to[1].push_back(x);
    if(done){puts("0");return 0;}
    
    vector<int> empties;
    for(int i = 1;i <= n;i++){
        if(files[i] == 0)empties.push_back(i);        
    }
    if(empties.empty()){
        int ind = go_to[0][0];
        move(ind, 0);
        empties.push_back(pos[ind]);
        pos[ind] = 0;
        f[ind] = "0";        
    }
    for(auto v:empties){
        while(true){
            int dest = v <= e;
            int nxt = go_to[dest].back();go_to[dest].pop_back();
            if(pos[nxt] == 0){
                move(nxt, v);
                break;
            }
            move(nxt, v);
            v = pos[nxt];
        }
    }
    cout << commands.size() << endl;
    for(auto command: commands)cout << command << endl;
    return 0;
}
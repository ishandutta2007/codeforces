//#include <bits/stdc++.h>
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int ar[50][20];
bool check(int vx, int y, int vy){
    set0(ar);
    for(int i = 0; i < y; i++){
        vy -= 25;
        ar[i][1] = 25;
    }
    for(int i = y; i < y + 3; i++){
        if(i == 4) {
            ar[i][0] = 15;
            vx -= 15;
        }
        else {
            ar[i][0] = 25;
            vx -= 25;
        }
    }
    if(vx < 0 || vy < 0) return false;
    if(vy >= ar[y+2][0]-2){
        vy -= ar[y+2][0]-2;
        ar[y+2][1] = ar[y+2][0] - 2;
        int p = min(vx, vy);
        ar[y+2][0] += p;
        ar[y+2][1] += p;
        vx -= p;
        vy -= p;
    }
    
    for(int i = 0; i < y; i++){
        int lft = ar[i][1] - 2 - ar[i][0];
        if(vx >= lft) {
            vx -= lft;
            ar[i][0] += lft;
        } else {
            ar[i][0] += vx;
            vx = 0;
        }
    }
    for(int i = y; i < y + 3; i++){
        int lft = ar[i][0] - 2 - ar[i][1];
        if(vy >= lft) {
            vy -= lft;
            ar[i][1] += lft;
        } else {
            ar[i][1] += vy;
            vy = 0;
        }
    }
    return vx == 0 && vy == 0;
}

bool check2(int vx, int y, int vy){
    set0(ar);
    for(int i = 0; i < y; i++){
        vy -= 25;
        ar[i][1] = 25;
    }
    for(int i = y; i < y + 3; i++){
        if(i == 4) {
            ar[i][0] = 15;
            vx -= 15;
        }
        else {
            ar[i][0] = 25;
            vx -= 25;
        }
    }
    if(vx < 0 || vy < 0) return false;
    if(y > 0 && vx >= ar[0][1]-2){
        vx -= ar[0][1]-2;
        ar[0][0] = ar[0][1] - 2;
        int p = min(vx, vy);
        ar[0][0] += p;
        ar[0][1] += p;
        vx -= p;
        vy -= p;
    }
    
    for(int i = 0; i < y; i++){
        int lft = ar[i][1] - 2 - ar[i][0];
        if(vx >= lft) {
            vx -= lft;
            ar[i][0] += lft;
        } else {
            ar[i][0] += vx;
            vx = 0;
        }
    }
    for(int i = y; i < y + 3; i++){
        int lft = ar[i][0] - 2 - ar[i][1];
        if(vy >= lft) {
            vy -= lft;
            ar[i][1] += lft;
        } else {
            ar[i][1] += vy;
            vy = 0;
        }
    }
    return vx == 0 && vy == 0;
}

int main(){
	//freopen("C:\\Home\\ContestCodes\\data.in", "r", stdin);
	ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    FOR(ts, 1, T+1){
		//cout << ts << " ";
        int x, y; cin >> x >> y;
        bool found = false;
        for(int i = 0; i <= 2; i++){
            if(found) continue;
            if(check(x, i, y)) {
                cout << 3 << ":" << i << endl;
                REP(j, 3+i) {
                    if(j) cout << " ";
                    cout << ar[j][0] << ":" << ar[j][1];
                }
                cout << endl;
                found = true;
            }
            else if(check2(x, i, y)) {
                cout << 3 << ":" << i << endl;
                REP(j, 3+i) {
                    if(j) cout << " ";
                    cout << ar[j][0] << ":" << ar[j][1];
                }
                cout << endl;
                found = true;
            }
        }
        for(int i = 2; i >= 0; i--){
            if(found) continue;
			if (check(x, i, y) != check2(x, i, y)) {
				printf(">>>%d %d\n", x, y);
				assert(0);
			}
			if(check(y, i, x)) {
                cout << i << ":" << 3 << endl;
                REP(j, 3+i) {
                    if(j) cout << " ";
                    cout << ar[j][1] << ":" << ar[j][0];
                }
                cout << endl;
                found = true;
            }
            else if(check2(y, i, x)) {
                cout << i << ":" << 3 << endl;
                REP(j, 3+i) {
                    if(j) cout << " ";
                    cout << ar[j][1] << ":" << ar[j][0];
                }
                cout << endl;
                found = true;
            }
        }
        if(!found) cout << "Impossible" << endl;
    }
}
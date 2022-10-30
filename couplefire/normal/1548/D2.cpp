#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 6006;

int n;
array<int, 2> pts[N], mpts[N];
int cnt[N][4][4][4];

int area(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3){
    return abs(x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1)%4ll;
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i<n; ++i){
        int x, y; cin >> x >> y;
        pts[i] = {x, y};
        mpts[i] = {x%4, y%4};
    }
    for(int i = 0; i<n; ++i){
        for(int j = i+1; j<n; ++j){
            int tmp = __gcd(abs(pts[i][0]-pts[j][0]), abs(pts[i][1]-pts[j][1]))%4;
            ++cnt[i][mpts[j][0]][mpts[j][1]][tmp];
            ++cnt[j][mpts[i][0]][mpts[i][1]][tmp];
        }
    }
    ll ooe = 0, eee = 0;
    for(int i = 0; i<n; ++i){
        for(int b1 = 0; b1<4; ++b1){
            for(int b2 = b1; b2<4; b2+=2){
                for(int s1 = 0; s1<16; ++s1){
                    int tmp = (b1<b2?0:s1);
                    for(int s2 = tmp; s2<16; ++s2){
                        int x1 = s1/4, y1 = s1%4;
                        int x2 = s2/4, y2 = s2%4;
                        if(x1%2 != x2%2 || y1%2 != y2%2) continue;
                        int b3, lol = 0;
                        if(x1==x2 && y1==y2){
                            b3 = 0;
                            if(b1==b2) lol = cnt[i][x1][y1][b1]*(cnt[i][x1][y1][b1]-1)/2;
                            else lol = cnt[i][x1][y1][b1]*cnt[i][x2][y2][b2];
                        } else{
                            b3 = 2;
                            lol = cnt[i][x1][y1][b1]*cnt[i][x2][y2][b2];
                        }
                        if((int)area(mpts[i][0], mpts[i][1], x1, y1, x2, y2)==((b1+b2+b3)%4)){
                            if(b1%2) ooe += lol;
                            else eee += lol;
                        }
                    }
                }
            }
        }
    }
    cout << eee/3+ooe << '\n';
}
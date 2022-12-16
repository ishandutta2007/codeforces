#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<int, int> pii;

const uint pbit = (1<<31);

inline pii gp(const uint& x) {
    return pii((x&((1<<24)-1)), ((x>>24)&((1<<7)-1)));
}
inline uint form(const int& a, const int& b) {
    return ((a&((1<<24)-1)) | (b<<24)) | pbit;
}
inline uint form(const pii& p) {
    return form(p.first, p.second);
}
inline uint gmax(const uint& a, const uint& b) {
    return (gp(a).first > gp(b).first ? a : b) | pbit;
}

uint dp[20001][52][100];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K, P;
    cin >> N >> K >> P;
    vector<int> v(N);
    for(int& ii : v) cin >> ii;

    dp[0][0][0] = form(0,0);

    for(int i=0;i<N;++i) {
        for(int j=0;j<=K;++j) {
            for(int k=0;k<P;++k) {
                if(dp[i][j][k]&pbit) {
                    //cerr << "FROM [" << i << "][" << j << "][" << k << "] = " << gp(dp[i][j][k]).first << "," << gp(dp[i][j][k]).second << " TO \n";
                    dp[i+1][j+1][v[i]%P] = gmax(dp[i+1][j+1][v[i]%P], 
                                          form(gp(dp[i][j][k]).first + v[i]%P, v[i]%P));
                    
                    //cerr << "    [" << i+1 << "][" << j+1 << "][" << v[i]%P << "] = " << gp(dp[i+1][j+1][v[i]%P]).first << "," << gp(dp[i+1][j+1][v[i]%P]).second << endl;
					if(i!= 0) {
						int nextra = (gp(dp[i][j][k]).second + v[i])%P;
						int nsum = gp(dp[i][j][k]).first - gp(dp[i][j][k]).second + nextra;
						dp[i+1][j][nextra] = gmax(dp[i+1][j][nextra],
											 form(nsum, nextra));
						//cerr << "    [" << i+1 << "][" << j << "][" << (nextra) << "] = " << gp(dp[i+1][j][nextra]).first << "," << gp(dp[i+1][j][nextra]).second << endl;
					}
                }
            }
        }
    }

    int best = 0;
    for(int k=0;k<P;++k) {
        best = max(gp(dp[N][K][k]).first, best);
    }
    cout << best << endl;
    
    return 0;
}
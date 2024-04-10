#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#define int long long
using namespace std;
int n, ai;
vector<int> data;
int K = 1000000007;
vector<int> fact;
int gcd (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int get(int nn, int kk){
    int zn = fact[kk] * fact[nn - kk]; zn%=K;
    int x, y;
    gcd(zn, K, x, y);
    return (x * fact[nn]) % K;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    fact.push_back(1);
    int now = 1;
    for (int i=1;i<1e6;i++){
        fact.push_back(now);
        now *= (i+1); now %= K;
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    int go = (n - 1) / 4 * 2;
    vector<int> newton;
    for (int i=0;i<(go + 1) * 2 +1;i++){
        if (i % 2 == 0) newton.push_back(0);
        else newton.push_back(get(go, i/2));
    }
    vector<int> f1, f2, f3, f4; f1.push_back(-1); f1.push_back(-1); f1.push_back(1); f2.push_back(1); f2.push_back(1); f2.push_back(-1);
    f3.push_back(-1); f3.push_back(1); f3.push_back(1); f4.push_back(1); f4.push_back(-1); f4.push_back(-1);
    vector<int> v1, v2, v3, v4;
    for (int i=0;i<newton.size();i++){v1.push_back(newton[i]);v2.push_back(newton[i]);v3.push_back(newton[i]);v4.push_back(newton[i]);}
    for (int i=0;i<(n-1)%4;i++){
         vector<int> vv1, vv2, vv3, vv4; vv1.push_back(0); vv2.push_back(0); vv3.push_back(0); vv4.push_back(0);
         for (int j=0;j<v1.size()-1;j++){
             vv1.push_back(v1[j] + f1[i] * v1[j+1]); vv2.push_back(v2[j]+f2[i]*v2[j+1]); vv3.push_back(v3[j]+f3[i]*v3[j+1]); vv4.push_back(v4[j]+f4[i]*v4[j+1]);
             f1[i]*=-1; f2[i]*=-1; f3[i]*=-1; f4[i]*=-1;
         }
         vv1.push_back(0); vv2.push_back(0); vv3.push_back(0); vv4.push_back(0); v1 = vv1; v2 = vv2; v3 = vv3; v4 = vv4;
    }
    int ans = 0;
    for (int i=0;i<v1.size();i++){
        v1[i] %= K; v2[i] %= K; v3[i] %= K; v4[i] %= K;
    }
    for (int i=0;i<n;i++){
        if (i % 2==0 && n % 2 != 0){
            ans += data[i]*v3[n-i];
            ans %= K;
        }
        else if (i% 2 == 0){
            ans += data[i]*v1[n-i];
            ans %= K;
        }
        else if (n % 2 != 0){
            ans += data[i]*v4[n-i];
            ans %= K;
        }
        else{
            ans += data[i]*v2[n-i];
            ans %= K;
        }
    }
    ans %= K;
    ans += K;
    cout << ans % K << endl;
    return 0;
}
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9
string s;
vector<int> g[2001];
int n;
__int64 d[2002];
__int64 ans =0;
__int64 h[2001][2001],h2[2001][2001];

__int64 hash(char c){
    return (__int64)c-(__int64)'a'+1;
}

int main(){
    cin >> s;
    n=s.size();
    for (int i=1;i<=n;i++){
        h[i][i]=hash(s[i-1]);
        for (int j=i+1;j<=n;j++)
            h[i][j]=h[i][j-1]*31 + hash(s[j-1]);
    }
    for (int i=n;i>0;i--){
        h2[i][i]=hash(s[i-1]);
        for (int j=i-1;j>0;j--)
            h2[j][i]=h2[j+1][i]*31 + hash(s[j-1]);
    }

    for (int i=1;i<=n;i++){
        g[i].push_back(i);
        for (int j=i+1;j<=n;j++){
            int len = j-i+1;
            int l = len/2;
            int tt1 = i+l-1, tt2 = j-l+1;
            if (len%2 == 1){
                tt1++;
                tt2--;
            }
            if (h[i][tt1]==h2[tt2][j])
                g[i].push_back(j);
        }
    }

    d[n+1]=0;
    for (int i=n;i>0;i--)
        d[i]=d[i+1]+g[i].size();

    for (int i=1;i<=n;i++)
        for (int j=0;j<g[i].size();j++)
             ans += d[g[i][j]+1];
    cout << ans << endl;
	return 0;
}
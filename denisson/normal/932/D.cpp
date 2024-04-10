#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int q;
int up[20][400007];
int up2[20][400007];
ll ma[20][400007];
ll sum[400007];
ll w[400007];
int len[400007];

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> q;
   	ll last = 0;
   	int cnt = 1;
   	for (int i = 0; i < 20; i++) up[i][1] = 1;
   	len[1] = 1;
   	while(q--){
   		int type;
   		ll w1, w2;	
   		cin >> type >> w1 >> w2;
   		ll v = w1 ^ last;
   		ll c = w2 ^ last;
//   		cout << "===" << type << ' ' << v << ' ' << c << endl;
   		if (type == 1){
   			int now = cnt + 1;
   			cnt++;
   			w[now] = c;
   			up2[0][now] = v;
   			ma[0][now] = w[v];
   			for (int i = 1; i < 20; i++){
   				up2[i][now] = up2[i - 1][up2[i - 1][now]];
   				ma[i][now] = max(ma[i - 1][now], ma[i - 1][up2[i - 1][now]]);
   			}
   			if (ma[19][now] < w[now]){
   				for (int i = 0; i < 20; i++) up[i][now] = now;
   				sum[now] = w[now];
   				len[now] = 1;
   			} else {
   				int pred = now;
   				for (int i = 19; i >= 0; i--){
   					if (ma[i][pred] < w[now]) pred = up2[i][pred];
   				}

   				pred = up2[0][pred];
   				//cout << now << ' ' << pred << ' ' << ma[0][now] << endl;
   				up[0][now] = pred;
   				for (int i = 1; i < 20; i++) up[i][now] = up[i - 1][up[i - 1][now]];
   				sum[now] = sum[pred] + w[now];
   				len[now] = len[pred] + 1;
   			}
   		} else {
   			if (sum[v] <= c){
   				last = len[v];
   				cout << len[v] << '\n';
   				continue;
   			}
   			int start = v;
   			for (int i = 19; i >= 0; i--){
   				if (sum[start] - sum[up[i][v]] <= c) v = up[i][v];
   			}
   			last = len[start] - len[v];
   			cout << last << "\n";
   		}
   	}
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 +100;
typedef long long ll;
bool used[maxn];
vector<int> prime;
void sieve(int size){
    for (int i=2;i<=size;i++){
        if (!used[i]){
            prime.push_back(i);
        }
        for (int j = 0;j < prime.size();j++){
            ll nxt = 1ll * i * prime[j];
            if (nxt > size)break;
            used[nxt] = 1;
            if (i % prime[j]){
            }else{
                break;
            }
        }
    }
}
int fa[maxn];
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u,int v){
    fa[find(u)] = find(v);
}
int main(){
    ll N;
    ll NN;
    cin>>N;
    NN = N;
    sieve(1e6+5);
    int least = 0;
    for (int x : prime){
        if (x < NN and NN % x == 0){
            least = x;
            while (N % x == 0){
                N /= x;
            }
            break;
        }
    }
    if (least == 0){
        cout<<NN<<endl;
        return 0;
    }
    for (int i=0;i<least;i ++){
        fa[i] = i;
    }
    for (int x : prime){
        if (x > least and x < NN and NN % x == 0){
            for (int u=1;u<=least;u++){
                int v = u + x;
                if (v > NN)break;
                merge(u % least,v % least);
            }
            while (N % x == 0)N /= x;
        }
    }
    if (N != 1){
        for (int u=1;u<=least;u++){
            ll v = u + N;
            if (v > NN)break;
            merge(u % least,v % least);
        }
    }
    int ans = 0;
    for (int i=1;i<=least;i++){
        ans += (find(i-1) == i-1);
    }
    cout<<ans<<endl;
    return 0;
}
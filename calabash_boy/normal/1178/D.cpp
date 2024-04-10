#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 100;
vector<pair<int,int> > ans(0);
int n;
bool used[1000000 + 5];
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
void output(){
    cout<<ans.size()<<endl;
    for (auto pr : ans){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    exit(0);
}
int main(){
    sieve(1000000);
    cin>>n;
    for (int i=1;i<n;i++){
        ans.emplace_back(i,i+1);
    }
    ans.emplace_back(n,1);
    int m = n;
    if (!used[m]){
        output();
    }
    for (int i=1;i<n-1;i+=4){
        m ++;
        ans.emplace_back(i, i+2);
        if (!used[m]){
            output();
        }
    }
    for (int i=2;i<n-1;i+=4){
        m++;
        ans.emplace_back(i,i+2);
        if (!used[m])output();
    }
    assert(0);
    return 0;
}
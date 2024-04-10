//https://codeforces.com/problemset/problem/327/E
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long permu[27];
vector<long long> a1, a2;
long long n;

long long solv1(long long n1){
    long long total = permu[n];
        map<long long, vector<long long>> occur;
        for(long long i = 0; i<(1<<a2.size()); i++){
            long long sum = 0;
            for(long long j = 0; j<a2.size(); j++){
                if(!(i&(1<<j))) continue;
                sum += a2[j];
            }
            occur[sum].push_back(__builtin_popcountll(i));
        }
        map<pair<long long, long long>, long long> mmp;
        for(long long i = 0; i<(1<<a1.size()); i++){
            long long sum = 0;
            for(long long j = 0; j<a1.size(); j++){
                if(!(i&(1<<j))) continue;
                sum += a1[j];
            }
            long long temp = n1-sum;
            long long sz = __builtin_popcountll(i);
            if(mmp.count({temp, sz})){
                total -= mmp[{temp, sz}];
                total %= MOD;
            }
            else{
                long long bruh = 0;
                for(auto x : occur[temp]){
                    total -= permu[x+sz]*permu[n-x-sz];
                    bruh += permu[x+sz]*permu[n-x-sz];
                    bruh %= MOD;
                    total %= MOD;
                }
                mmp[{temp, sz}] = bruh;
            }
        }
        return ((total%MOD)+MOD)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    permu[0] = 1;
    for(long long i = 1; i<27; i++){
        permu[i] = (permu[i-1]*i)%MOD;
    }
    cin >> n;
    long long arr[n];
    for(long long i = 0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for(long long i = 0; i<n; i++){
        if(i < (n+1)/2) a1.push_back(arr[i]);
        else a2.push_back(arr[i]);
    }
    long long k; cin >> k;
    if(k == 0){
        cout << permu[n] << endl;
        return 0;
    }
    else if(k == 1){
        long long n1; cin >> n1;
        cout << solv1(n1) << endl;
        return 0;
    }
    long long total = permu[n];
    long long n1, n2; cin >> n1 >> n2;
    if(n1 < n2) swap(n1, n2);
    total -= (permu[n]-solv1(n1));
    total -= (permu[n]-solv1(n2));
    map<pair<long long, long long>, vector<pair<long long, long long>>> occur;
    for(long long i = 0; i<(1<<a2.size()); i++){
        long long sum = 0;
        for(long long j = 0; j<a2.size(); j++){
            if(!(i&(1<<j))) continue;
            sum += a2[j];
        }
        for(long long j = i; ; j=(j-1)&i){
            long long sum2 = 0;
            for(long long l = 0; l<a2.size(); l++){
                if(!(j&(1<<l))) continue;
                sum2 += a2[l];
            }
            occur[{sum, sum2}].push_back({__builtin_popcountll(i), __builtin_popcountll(j)});
            if(j == 0) break;
        }
    }
    map<pair<pair<long long, long long>, pair<long long, long long>>, long long> mmp;
    for(long long i = 0; i<(1<<a1.size()); i++){
        long long sum = 0;
        for(long long j = 0; j<a1.size(); j++){
            if(!(i&(1<<j))) continue;
            sum += a1[j];
        }
        for(long long j = i; ; j=(j-1)&i){
            long long sum2 = 0;
            for(long long l = 0; l<a1.size(); l++){
                if(!(j&(1<<l))) continue;
                sum2 += a1[l];
            }
            //cout << sum << " " << sum2 << endl;
            long long t1 = n1-sum;
            long long t2 = n2-sum2;
            if(mmp.count({{t1, t2}, {__builtin_popcountll(i), __builtin_popcountll(j)}})){
                total += mmp[{{t1, t2}, {__builtin_popcountll(i), __builtin_popcountll(j)}}];
                total %= MOD;
            }
            else{
                long long bruh = 0;
                for(auto x : occur[{t1, t2}]){
                    total += (permu[x.second+__builtin_popcountll(j)]*permu[x.first+__builtin_popcountll(i)-x.second-__builtin_popcountll(j)]%MOD)*permu[n-x.first-__builtin_popcount(i)];
                    bruh += (permu[x.second+__builtin_popcountll(j)]*permu[x.first+__builtin_popcountll(i)-x.second-__builtin_popcountll(j)]%MOD)*permu[n-x.first-__builtin_popcount(i)];
                    bruh %= MOD;
                    total %= MOD;
                }
                mmp[{{t1, t2}, {__builtin_popcountll(i), __builtin_popcountll(j)}}] = bruh;
            }
            if(j == 0) break;
        }
    }
    cout << ((total%MOD)+MOD)%MOD << endl;
}